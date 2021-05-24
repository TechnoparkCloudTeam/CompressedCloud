#include "../include/WatcherNotifierBuilder.h"

WatcherNotifierBuilder::WatcherNotifierBuilder() :
    mWatcher(std::make_shared<Watcher>())
{
}

auto WatcherNotifierBuilder::run() -> void {
    while (true) {
        if (mWatcher->isStopped()) {
            break;
        }
        runOnce();
    }
}

auto WatcherNotifierBuilder::runOnce() -> void {
    if (mWatcher->isStopped()) {
        return;
    }
    auto fileSysEvent = mWatcher->getNextEvent();
    if (!fileSysEvent) {
        return;
    }

    InotifyEvent currentEvent = static_cast<InotifyEvent>(fileSysEvent->EventMask);

    WatcherNotification notification { currentEvent, fileSysEvent->EventTime, fileSysEvent->Path};

    for (auto& eventAndEventObserver : mEventObserver) {
        auto& event = eventAndEventObserver.first;
        auto& eventObserver = eventAndEventObserver.second;

        if (event == InotifyEvent::_all) {
            eventObserver(notification);
            return;
        }

        if (event == currentEvent) {
            eventObserver(notification);
            return;
        }

        if (mUnexpectedObserver) {
            mUnexpectedObserver(notification);
        }
    }
}
auto WatcherNotifierBuilder::stop() -> void {
    mWatcher->shutDown();
}

auto WatcherNotifierBuilder::watchPathRecursively(fsPath path) -> WatcherNotifierBuilder& {
    mWatcher->watchDirRecursive(path);
    return *this;
}

auto WatcherNotifierBuilder::watchFile(fsPath file) -> WatcherNotifierBuilder& {
    mWatcher->watchFile(file);
    return *this;
}

auto WatcherNotifierBuilder::unwatchFile(fsPath file) -> WatcherNotifierBuilder& {
    mWatcher->unwatchFile(file);
    return *this;
}

auto WatcherNotifierBuilder::ignoreFileOnce(fsPath file) -> WatcherNotifierBuilder& {
    mWatcher->ignoreFileOnce(file.string());
    return *this;
}

auto WatcherNotifierBuilder::onEvent(InotifyEvent event, EventObserver eventObserver) -> WatcherNotifierBuilder& {
    mWatcher->setEventMask(mWatcher->getEventMask() | static_cast<std::uint32_t>(event));
    mEventObserver[event] = eventObserver;
    return *this;

}

auto WatcherNotifierBuilder::onEvents(vector<InotifyEvent> events, EventObserver eventObserver) -> WatcherNotifierBuilder& {
    for (auto event : events) {
        mWatcher->setEventMask(mWatcher->getEventMask() | static_cast<std::uint32_t>(event));
        mEventObserver[event] = eventObserver;
    }

    return *this;
}

auto WatcherNotifierBuilder::onUnexpectedEvent(EventObserver eventObserver) -> WatcherNotifierBuilder& {
    mUnexpectedObserver = eventObserver;
    return *this;
}

auto WatcherNotifierBuilder::setEventTimeout(milliseconds timeout, EventObserver eventObserver) -> WatcherNotifierBuilder& {
    auto onEventTimeout = [eventObserver](FileSysEvent fileSystemEvent) {
        WatcherNotification notification { static_cast<InotifyEvent>(fileSystemEvent.EventMask),
                                            fileSystemEvent.EventTime,
                                            fileSystemEvent.Path};
        eventObserver(notification);
    };

    mWatcher->setEventTimeout(timeout, onEventTimeout);
    return *this;
}

WatcherNotifierBuilder BuildWatcherNotifier() {
    return {};
}

auto WatcherNotifierBuilder::runAfterShutDown() -> void {
    mWatcher->runAfterShutDown();
}