#pragma once
#include <sys/inotify.h>
#define MAX_EVENTS_COUNT 1024 // Event count proccessed at the same time
#define MAX_FILE_LEN 20
#define EVENT_SIZE (sizeof (struct inotify_event))
#define BUFFER_LEN (MAX_EVENTS_COUNT * (EVENT_SIZE + MAX_FILE_LEN))