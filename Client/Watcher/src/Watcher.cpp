#include "../include/Watcher.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/epoll.h>

#include <iostream>

Watcher::Watcher() :
    mError(0),
    mEventTimeout(0),
    mLastEventTime(steadyClock::now()),
    mEventMask(IN_ALL_EVENTS),
    mThreadSleep(250),
    mIgnoredDirs(vector<string>()),
    mInotifyFileDescriptor(0),
    mOnEventTimeout([](FileSysEvent) {}),
    mEventBuffer(MAX_EVENTS_COUNT * (EVENT_SIZE + ADDITIONAL_EVENT_SIZE), 0),
    mPipeReadIdx(0),
    mPipeWriteIdx(0) 
{
    mStopped = false;

    if (pipe2(StopPipeFileDescriptor, O_NONBLOCK) == ERROR_DESC) {
        mError = errno;
        stringstream errorStream;
        errorStream << "Cannot initialize stop pipe !" << strerror(mError) << ".";
        throw std::runtime_error(errorStream.str());
    }
    mInotifyFileDescriptor = inotify_init1(IN_NONBLOCK);
    if (mInotifyFileDescriptor == ERROR_DESC) {
        mError = errno;
        stringstream errorStream;
        errorStream << "Can't initialize inotify ! " << strerror(mError) << ".";
        throw std::runtime_error(errorStream.str());
    }
    mEpollFd = epoll_create1(0);
    if (mEpollFd == ERROR_DESC) {
        mError = errno;
        std::stringstream errorStream;
        errorStream << "Can't initialize epoll ! " << strerror(mError) << ".";
        throw std::runtime_error(errorStream.str());
    }

    mInotifyEpollEvent.events = EPOLLIN | EPOLLET;
    mInotifyEpollEvent.data.fd = mInotifyFileDescriptor;
    if (epoll_ctl(mEpollFd, EPOLL_CTL_ADD, mInotifyFileDescriptor, &mInotifyEpollEvent) == ERROR_DESC) {
        mError = errno;
        stringstream errorStream;
        errorStream << "Cannot add inotify discriptor to epoll !" << strerror(mError) << ".";
        throw std::runtime_error(errorStream.str());
    }

    mStopPipeEpollEvent.events = EPOLLIN || EPOLLET;
    mStopPipeEpollEvent.data.fd = StopPipeFileDescriptor[mPipeReadIdx];
    if (epoll_ctl(mEpollFd, EPOLL_CTL_ADD, StopPipeFileDescriptor[mPipeReadIdx], &mStopPipeEpollEvent) == ERROR_DESC) {
        mError = errno;
        stringstream errorStream;
        errorStream << "Cannot add file discriptor to epoll !" << strerror(mError) << ".";
        throw std::runtime_error(errorStream.str());
    }
}

Watcher::~Watcher() {
    epoll_ctl(mEpollFd, EPOLL_CTL_DEL, mInotifyFileDescriptor, 0);
    epoll_ctl(mEpollFd, EPOLL_CTL_DEL, StopPipeFileDescriptor[mPipeReadIdx], 0);

    if (!close(mInotifyFileDescriptor)) {
        mError = errno;
    }

    if (!close(mEpollFd)) {
        mError = errno;
    }

    close(StopPipeFileDescriptor[mPipeReadIdx]);
    close(StopPipeFileDescriptor[mPipeWriteIdx]);
}

void Watcher::watchDirRecursive(fsPath path) {
    vector<fsPath> paths;
    if (fs::exists(path)) {
        paths.push_back(path);

        if (fs::is_directory(path)) {
            std::error_code ec;
            fs::recursive_directory_iterator it(
                path, fs::directory_options::follow_directory_symlink, ec);
            fs::recursive_directory_iterator end;

            for (; it != end; it.increment(ec)) {
                fsPath currentPath = *it;

                if (!fs::is_directory(currentPath) && 
                !fs::is_symlink(currentPath)) {
                    continue;
                }

                paths.push_back(currentPath);
            }
        }
    } else {
        throw std::invalid_argument("Can't watch Path! Path does not exist. Path" + path.string());
    }

    for (auto& path : paths) {
        watchFile(path);
    }
}

void Watcher::watchFile(fsPath file) {
    if (fs::exists(file)) {
        mError = 0;
        int watchDescriptor = 0;
        if (!isIgnored(file)) {
            watchDescriptor = inotify_add_watch(mInotifyFileDescriptor,
             file.string().c_str(), mEventMask);
        }

        if (watchDescriptor == ERROR_DESC) {
            mError = errno;
            stringstream errorStream;
            if (mError == NO_SPACE_LEFT) {
                errorStream << "Failed to watch! " << strerror(mError) << 
                ". Please increase number of watches in "
                "\"/proc/sys/fs/inotify/max_user_watches\".";
                throw std::runtime_error(errorStream.str());
            }

            errorStream << "Failed to watch! " << strerror(mError) 
                << ". Path: " << file.string();
        }
        mDirectoriesMap.left.insert({watchDescriptor, file});
    } else {
        throw std::invalid_argument(
            "Can't watch Path! Path does not exist. Path: " + file.string());
    }
}

void Watcher::ignoreFileOnce(fsPath file) {
    mOnceIgnoredDirs.push_back(file.string());
}

void Watcher::ignoreFile(fsPath file) {
    mIgnoredDirs.push_back(file.string());
}

void Watcher::unwatchFile(fsPath file) {
    removeWatch(mDirectoriesMap.right.at(file));
}

void Watcher::removeWatch(int watchDescriptor) {
    int result = inotify_rm_watch(mInotifyFileDescriptor, watchDescriptor);
    if (result == ERROR_DESC) {
        mError = errno;
        stringstream errorStream;
        errorStream << "Failed to remove watch! " << strerror(mError) << ".";
        throw std::runtime_error(errorStream.str());
    }
}

fsPath Watcher::wdToPath(int watchDescriptor) {
    return mDirectoriesMap.left.at(watchDescriptor);
}

void Watcher::setEventMask(uint32_t eventMask) {
    this->mEventMask = eventMask;
}

uint32_t Watcher::getEventMask() {
    return mEventMask;
}

void Watcher::setEventTimeout(milliseconds eventTimeout, function<void(FileSysEvent)> onEventTimeout) {
    mLastEventTime -= eventTimeout;
    mEventTimeout = eventTimeout;
    mOnEventTimeout = onEventTimeout;
}

std::optional<FileSysEvent> Watcher::getNextEvent() {
    vector<FileSysEvent> newEvents;
    while (mEventQueue.empty() && !mStopped) {
        auto length = readEventsIntoBuffer(mEventBuffer);
        readEventsFromBuffer(mEventBuffer.data(), length, newEvents);
        filterEvents(newEvents, mEventQueue);
    }

    if (mStopped) {
        return std::nullopt;
    }

    auto event = mEventQueue.front();
    mEventQueue.pop();
    return event;
}

void Watcher::shutDown() {
    mStopped = true;
    sendStopSignal();
}

bool Watcher::isStopped() {
    return mStopped;
}

bool Watcher::isIgnored(string file) {
    for (unsigned i = 0; i < mOnceIgnoredDirs.size(); ++i) {
        size_t pos = file.find(mOnceIgnoredDirs[i]);
        if (pos != string::npos) {
            mOnceIgnoredDirs.erase(mOnceIgnoredDirs.begin() + i);
            return true;
        }
    }
    
    for (unsigned i = 0; i < mOnceIgnoredDirs.size(); ++i) {
        size_t pos = file.find(mOnceIgnoredDirs[i]);
        if (pos != string::npos) {
            return true;
        }
    }
    return false;
}

bool Watcher::isOnTimeout(const steadyClock::time_point &eventTime) {
    return std::chrono::duration_cast<milliseconds>(eventTime - mLastEventTime) < mEventTimeout;
}

ssize_t Watcher::readEventsIntoBuffer(vector<uint8_t>& eventBuffer) {
    ssize_t length = 0;
    auto timeout = 1;
    auto nFileDescReady = epoll_wait(mEpollFd, mEpollEvents, MAX_EPOLL_EVENTS, timeout);
    if (nFileDescReady == ERROR_DESC) {
        return length;
    }

    for (auto n = 0; n < nFileDescReady; ++n) {
        if (mEpollEvents[n].data.fd == StopPipeFileDescriptor[mPipeReadIdx]) {
            break;
        }
        length = read(mEpollEvents[n].data.fd, eventBuffer.data(), eventBuffer.size());
        if (length == ERROR_DESC) {
            mError = errno;
            if (mError == EINTR) {
                break;
            }
        }
    }
    return length;
}

void Watcher::readEventsFromBuffer(uint8_t* buffer, int length, vector<FileSysEvent> &events) {
    int i = 0;
    while (i < length) {
        inotify_event* event = ((struct inotify_event*)& buffer[i]);

        if (event->mask & IN_IGNORED) {
            i += EVENT_SIZE + event->len;
            mDirectoriesMap.left.erase(event->wd);
            continue;
        }

        auto path = wdToPath(event->wd);

        if (fs::is_directory(path)) {
            path = path / string(event->name);
        }

        if (fs::is_directory(path)) {
            event->mask |= IN_ISDIR;
        }

        FileSysEvent fsEvent(event->wd, event->mask, path, std::chrono::steady_clock::now());

        if (!fsEvent.Path.empty()) {
            events.push_back(fsEvent);
        } else {
            //ignore
        }

        i += EVENT_SIZE + event->len;
    }
}

void Watcher::filterEvents(vector<FileSysEvent>& events,
    queue<FileSysEvent>& eventQueue) {
    for (auto eventIt = events.begin(); eventIt < events.end(); ) {
        FileSysEvent currentEvent = *eventIt;
        if (isOnTimeout(currentEvent.EventTime)) {
            eventIt = events.erase(eventIt);
            mOnEventTimeout(currentEvent);
        } else if (isIgnored(currentEvent.Path.string())) {
            eventIt = events.erase(eventIt);
        } else {
            mLastEventTime = currentEvent.EventTime;
            eventQueue.push(currentEvent);
            eventIt++;
        }
    }
}

void Watcher::sendStopSignal() {
    vector<std::uint8_t> buf(1, 0);
    write(StopPipeFileDescriptor[mPipeWriteIdx], buf.data(), buf.size());
}

void Watcher::runAfterShutDown() {
    mStopped = false;
}