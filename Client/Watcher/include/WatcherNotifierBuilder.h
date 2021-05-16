#pragma once

#include <memory>
#include <filesystem>
#include <string>
#include <map>

#include "Watcher.h"
#include "WatcherNotification.h"

using EventObserver = std::function<void(WatcherNotification)>;
using std::chrono::milliseconds;
using std::vector;
using std::map;
using fsPath = std::filesystem::path;

class WatcherNotifierBuilder {
    public:
    WatcherNotifierBuilder();

    auto run() -> void;
    auto runOnce() -> void;
    auto stop() -> void;
    auto watchPathRecursively(fsPath path) -> WatcherNotifierBuilder&;
    auto watchFile(fsPath file) -> WatcherNotifierBuilder&;
    auto unwatchFile(fsPath file) -> WatcherNotifierBuilder&;
    auto ignoreFileOnce(fsPath file) -> WatcherNotifierBuilder&;
    auto onEvent(InotifyEvent event, EventObserver eventObserver) -> WatcherNotifierBuilder&;
    auto onEvents(vector<InotifyEvent> events, EventObserver eventObserver) -> WatcherNotifierBuilder&;
    auto onUnexpectedEvent(EventObserver eventObserver) -> WatcherNotifierBuilder&;
    auto setEventTimeout(milliseconds timeout, EventObserver EventObserver) -> WatcherNotifierBuilder&;

    private:
    std::shared_ptr<Watcher> mWatcher;
    std::map<InotifyEvent, EventObserver> mEventObserver;
    EventObserver mUnexpectedObserver;
};

WatcherNotifierBuilder BuildWatcherNotifier();