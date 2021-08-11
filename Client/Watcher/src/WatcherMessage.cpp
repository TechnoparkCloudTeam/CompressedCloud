#include "../include/WatcherMessage.h"

bool hasInotifyEvent(const InotifyEvent &allEvents, const InotifyEvent &event)
{
    return (static_cast<std::uint32_t>(allEvents & event));
}

std::ostream &operator<<(std::ostream &stream, const InotifyEvent &event)
{
    std::string mask;

    if (hasInotifyEvent(event, InotifyEvent::_access))
    {
        mask.append("access ");
    }
    if (hasInotifyEvent(event, InotifyEvent::_remove))
    {
        mask.append("remove ");
    }
    if (hasInotifyEvent(event, InotifyEvent::_remove_self))
    {
        mask.append("remove_self ");
    }
    if (hasInotifyEvent(event, InotifyEvent::_modify))
    {
        mask.append("modify ");
    }
    if (hasInotifyEvent(event, InotifyEvent::_move))
    {
        mask.append("move ");
    }
    if (hasInotifyEvent(event, InotifyEvent::_move_self))
    {
        mask.append("move_self ");
    }
    if (hasInotifyEvent(event, InotifyEvent::_attrib))
    {
        mask.append("attrib ");
    }
    if (hasInotifyEvent(event, InotifyEvent::_create))
    {
        mask.append("create ");
    }
    if (hasInotifyEvent(event, InotifyEvent::_q_overflow))
    {
        mask.append("q_overflow");
    }
    if (hasInotifyEvent(event, InotifyEvent::_ignored))
    {
        mask.append("ignored ");
    }
    if (hasInotifyEvent(event, InotifyEvent::_oneshot))
    {
        mask.append("oneshot ");
    }
    if (hasInotifyEvent(event, InotifyEvent::_unmount))
    {
        mask.append("unmount ");
    }
    if (hasInotifyEvent(event, InotifyEvent::_is_dir))
    {
        mask.append("is_dir ");
    }

    if (hasInotifyEvent(event, InotifyEvent::_moved_to) &&
        hasInotifyEvent(event, InotifyEvent::_moved_from))
    {
        mask.append("move (moved_from | moved_to) ");
    }
    else
    {
        if (hasInotifyEvent(event, InotifyEvent::_moved_to))
        {
            mask.append("moved_to ");
        }
        if (hasInotifyEvent(event, InotifyEvent::_moved_from))
        {
            mask.append("moved_from ");
        }
    }

    if (hasInotifyEvent(event, InotifyEvent::_close_write) &&
        hasInotifyEvent(event, InotifyEvent::_close_nowrite))
    {
        mask.append("close (close_write | close_nowrite");
    }
    else
    {
        if (hasInotifyEvent(event, InotifyEvent::_close_nowrite))
        {
            mask.append("close_nowrite ");
        }
        if (hasInotifyEvent(event, InotifyEvent::_close_write))
        {
            mask.append("close_write");
        }
    }
    stream << mask;
    return stream;
}