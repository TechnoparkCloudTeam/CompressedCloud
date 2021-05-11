#pragma once
#include <sys/inotify.h>
#define MAX_EVENTS_COUNT 4096 // Event count proccessed at the same time
#define MAX_FILE_LEN 20
#define EVENT_SIZE (sizeof (struct inotify_event))
#define BUFFER_LEN (MAX_EVENTS_COUNT * (EVENT_SIZE + MAX_FILE_LEN))

enum Event : std::uint32_t {
    _access = IN_ACCESS, //file was accesed
    _in_attrib = IN_ATTRIB, //file attributes changed (ownership, permissions)
    _in_create = IN_CREATE, //file was created inside watched directory
    _in_delete = IN_DELETE, //file deleted inside watched directory
    _in_delete_self = IN_DELETE_SELF, //watched file was deleted
    _in_modify = IN_MODIFY, //watched file was modified
    _in_move_self = IN_MOVE_SELF //watched file was moved
};
