#include "../include/Watcher.h"



void Watcher::run(std::string Path) {
    int fd = inotify_init1(0);
    if (fd < 0) {
        std::cerr << "Could not initialize inotify";
    }
    int WatchDescriptor = inotify_add_watch(fd, Path.c_str(), IN_CLOSE | IN_MODIFY);
    if (WatchDescriptor == -1) {
        std::cerr << "Could'n add to watch " << Path << "\n";
    } else {
        std::cout << "Watching " << Path << "\n";
    }
    working = true;
    while (working) {
        int i = 0;
        int length = read( fd, buffer, BUFFER_LEN);
        if (length < 0) {
            std::cerr << "read error";
        }

        while (i < length) {
            struct inotify_event* event = (struct inotify_event*) &buffer[i];
            if (event->len) {
                if (event->mask & IN_CLOSE) {
                    if (event->mask & IN_ISDIR) {
                        std::cout << "The directory " << event->name << " was closed.\n";
                    } else {
                        std::cout << "The file " << event->name << " was closed with WD " << event->wd;
                    }
                }
            
                if (event->mask & IN_MODIFY) {
                    if (event->mask & IN_ISDIR) {
                        std::cout << "The directory " << event->name << " was modified.\n";
                    } else {
                        std::cout << "The file " << event->name << " was modified with WD " << event->wd << "\n";
                    }
                }
                i += EVENT_SIZE + event->len;
            }
        }
    }
    inotify_rm_watch(fd, WatchDescriptor);
    close(fd);
}

void Watcher::shutdown() {
    return;
}

bool Watcher::isWorking() {
    return 0;
}

void Watcher::SetEventMask(uint32_t EventMask) {
    return;
}

void Watcher::AddFileToWatch(std::string Path) {
    return;
}

void Watcher::AddDirToWatch() {
    return;
}

void Watcher::RemoveDirFromWatch() {
    return;
}

void Watcher::RemoveFileFromWatch() {
    return;
}

void Watcher::WriteEventsToBuffer() {
    return;
}