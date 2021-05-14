#include "../include/Watcher.h"
#include <fcntl.h>


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


}

Watcher::~Watcher() {

}

void Watcher::watchDirRecursive(fsPath path) {

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