#pragma once
#include <sys/inotify.h>
#define MAX_EVENTS_COUNT 4096 // Event count proccessed at the same time
#define MAX_EPOLL_EVENTS 1
#define EVENT_SIZE (sizeof(inotify_event))
#define PIPE_ERROR -1
