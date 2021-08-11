#include "../include/FileSysEvent.h"

FileSysEvent::FileSysEvent(
    int _WatchDescriptor,
    uint32_t _EventMask,
    const fsPath _Path,
    const timePoint _EventTime) : WatchDescriptor(_WatchDescriptor),
                                  EventMask(_EventMask),
                                  Path(_Path),
                                  EventTime(_EventTime) {}

FileSysEvent::~FileSysEvent() {}