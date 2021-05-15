#include "../Watcher/include/WatcherNotifierBuilder.h"

WatcherNotifierBuilder::WatcherNotifierBuilder() {

}

auto WatcherNotifierBuilder::run() -> void {

}

auto WatcherNotifierBuilder::runOnce() -> void {

}
auto WatcherNotifierBuilder::stop() -> void {

}

auto WatcherNotifierBuilder::watchPathRecursively(fsPath path) -> WatcherNotifierBuilder& {

}

auto WatcherNotifierBuilder::watchFile(fsPath file) -> WatcherNotifierBuilder& {

}

auto WatcherNotifierBuilder::unwatchFile(fsPath file) -> WatcherNotifierBuilder& {

}

auto WatcherNotifierBuilder::ignoreFileOnce(fsPath file) -> WatcherNotifierBuilder& {

}

auto WatcherNotifierBuilder::onEvent(InotifyEvent event, EventObserver) -> WatcherNotifierBuilder& {

}

auto WatcherNotifierBuilder::onEvents(vector<InotifyEvent> event, EventObserver) -> WatcherNotifierBuilder& {

}

auto WatcherNotifierBuilder::onUnexpectedEvent(EventObserver) -> WatcherNotifierBuilder& {

}

auto WatcherNotifierBuilder::setEventTimeout(milliseconds timeout, EventObserver EventObserver) -> WatcherNotifierBuilder& {
    
}