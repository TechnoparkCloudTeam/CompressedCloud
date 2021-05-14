#include "../include/WatcherNotification.h"

WatcherNotification::WatcherNotification(
        const InotifyEvent& event,
        const timePoint time,
        const std::filesystem::path path
    ) : 
    Event(event),
    Time(time),
    Path(path) {}
