#include "../include/Watcher.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/epoll.h>

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

    if (pipe2(StopPipeFileDescriptor, O_NONBLOCK) == PIPE_ERROR) {
        mError = errno;
        std::stringstream errorStream;
        errorStream << "Cannot initialize stop pipe !" << strerror(mError) << ".";
        throw std::runtime_error(errorStream.str());
    }
    mInotifyFileDescriptor = inotify_init1(IN_NONBLOCK);
    if (mInotifyFileDescriptor == PIPE_ERROR) {
        mError = errno;
        std::stringstream errorStream;
        errorStream << "Can't initialize inotify ! " << strerror(mError) << ".";
        throw std::runtime_error(errorStream.str());
    }
    mEpollFd = epoll_create1(0);
    if (mEpollFd == PIPE_ERROR) {
        mError = errno;
        std::stringstream errorStream;
        errorStream << "Can't initialize epoll ! " << strerror(mError) << ".";
        throw std::runtime_error(errorStream.str());
    }

    mInotifyEpollEvent.events = EPOLLIN | EPOLLET;
    mInotifyEpollEvent.data.fd = mInotifyFileDescriptor;
    if (epoll_ctl(mEpollFd, EPOLL_CTL_ADD, mInotifyFileDescriptor, &mInotifyEpollEvent) == PIPE_ERROR) {
        mError = errno;
        std::stringstream errorStream;
        errorStream << "Cannot add inotify discriptor to epoll !" << strerror(mError) << ".";
        throw std::runtime_error(errorStream.str());
    }

    mStopPipeEpollEvent.events = EPOLLIN || EPOLLET;
    mStopPipeEpollEvent.data.fd = StopPipeFileDescriptor[mPipeReadIdx];
    if (epoll_ctl(mEpollFd, EPOLL_CTL_ADD, StopPipeFileDescriptor[mPipeReadIdx], &mStopPipeEpollEvent) == PIPE_ERROR) {
        mError = errno;
        std::stringstream errorStream;
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

}

void Watcher::ignoreFileOnce(fsPath file) {

}

void Watcher::ignoreFile(fsPath file) {

}

void Watcher::setEventMask(uint32_t eventMask) {
    this->mEventMask = eventMask;
}

uint32_t Watcher::getEventMask() {
    return mEventMask;
}

void Watcher::setEventTimeout(milliseconds eventTimeout, function<void(FileSysEvent)> onEventTimeout) {

}

std::optional<FileSysEvent> Watcher::getNextEvent() {
    return std::optional<FileSysEvent>();
}

void Watcher::shutDown() {

}

bool Watcher::isStopped() {
    return false;
}