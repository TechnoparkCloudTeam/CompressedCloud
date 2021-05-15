#pragma once
#include <filesystem>
#include <chrono>
#include "WatcherMessage.h"

using timePoint = std::chrono::steady_clock::time_point;
using fsPath = std::filesystem::path;

class WatcherNotification {
    public:

    WatcherNotification(
        const InotifyEvent& event,
        const timePoint time,
        const std::filesystem::path path
    );

    const InotifyEvent Event;
    const timePoint Time;
    const fsPath Path;
};