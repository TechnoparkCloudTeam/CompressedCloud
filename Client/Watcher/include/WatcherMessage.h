#pragma once
#include <sys/inotify.h>
#include <iostream>
#include <cstdint>

enum class InotifyEvent : std::uint32_t {
    _create = IN_CREATE,
    _remove = IN_DELETE,
    _remove_self = IN_DELETE_SELF,
    _modify = IN_MODIFY,
    _access = IN_ACCESS,
    _attrib = IN_ATTRIB,
    _move_self = IN_MOVE_SELF,
    _moved_from = IN_MOVED_FROM,
    _moved_to = IN_MOVED_TO,
    _move = IN_MOVE,
    _close_write = IN_CLOSE_WRITE,
    _close_nowrite = IN_CLOSE_NOWRITE,
    _close = IN_CLOSE,
    _open = IN_OPEN,
    _is_dir = IN_ISDIR,
    _unmount = IN_UNMOUNT,
    _q_overflow = IN_Q_OVERFLOW,
    _ignored = IN_IGNORED,
    _oneshot = IN_ONESHOT,
    _all = IN_ALL_EVENTS
};

constexpr InotifyEvent operator&(InotifyEvent lhs, InotifyEvent rhs) {
    return static_cast<InotifyEvent>(
        static_cast<std::underlying_type<InotifyEvent>::type>(lhs)
        & static_cast<std::underlying_type<InotifyEvent>::type>(rhs));
}

constexpr InotifyEvent operator|(InotifyEvent lhs, InotifyEvent rhs) {
    return static_cast<InotifyEvent>(
        static_cast<std::underlying_type<InotifyEvent>::type>(lhs)
        | static_cast<std::underlying_type<InotifyEvent>::type>(rhs));
}

std::ostream& operator<<(std::ostream&  stream , const InotifyEvent& event);

bool hasInotifyEvent(const InotifyEvent& allEvents, const InotifyEvent& event);