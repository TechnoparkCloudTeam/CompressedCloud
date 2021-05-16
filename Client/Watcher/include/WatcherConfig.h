#pragma once
#include <sys/inotify.h>
#define MAX_EVENTS_COUNT 4096 // Event count proccessed at the same time
#define MAX_EPOLL_EVENTS 1
#define EVENT_SIZE (sizeof(inotify_event))
#define ERROR_DESC -1
#define ADDITIONAL_EVENT_SIZE 16
#define NO_SPACE_LEFT 28