#pragma once
#include <filesystem>
#include <string>
#include <chrono>

using timePoint = std::chrono::steady_clock::time_point;
using fsPath = std::filesystem::path;

class FileSysEvent
{
public:
    FileSysEvent(
        int _WatchDescriptor,
        uint32_t _EventMask,
        const fsPath _Path,
        const timePoint _EventTime);
    ~FileSysEvent();
    int WatchDescriptor;
    uint32_t EventMask;
    fsPath Path;
    timePoint EventTime;
};