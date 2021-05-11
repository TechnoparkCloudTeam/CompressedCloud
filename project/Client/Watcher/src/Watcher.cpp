#include "../include/Watcher.h"



void Watcher::run(std::string Path) {
    int length, i = 0, wd;
    int fd;
    char buffer[BUFFER_LEN];

     /* Инициализация Inotify*/
    fd = inotify_init1(0);
    if ( fd < 0 ) {
        perror( "Couldn't initialize inotify");
    }
     /* добавим наблюдение для директории*/
    wd = inotify_add_watch(fd, Path.c_str(), IN_CLOSE | IN_MODIFY | IN_CREATE | IN_DELETE);
    if (wd == -1)
    {
        printf("Couldn't add watch to %s\n",Path.c_str());
    }
    else
    {
        printf("Watching:: %s\n", Path);
    }

    while(1)
    {
        i = 0;
  	/* высчитываем размер файлового дескриптора*/
        length = read( fd, buffer, BUFFER_LEN );
        if ( length < 0 ) {
            perror( "read" );
        }

        while ( i < length ) {
        struct inotify_event *event = ( struct inotify_event * ) &buffer[ i ];
        if ( event->len ) {
            if ( event->mask & IN_CREATE) {
                
                if (event->mask & IN_ISDIR) {
                    printf( "The directory %s was created.\n", event->name );
                    Events.push(InotifyEvent(event->name, FileObjectStatus::CREATE, 1));
                }
                else {
                    printf( "The file %s was created with WD %d\n", event->name, event->wd );
                    Events.push(InotifyEvent(event->name, FileObjectStatus::CREATE, 0));
                }
            }
            if ( event->mask & IN_MODIFY) {
                if (event->mask & IN_ISDIR) {
                    printf( "The directory %s was modified.\n", event->name );
                    Events.push(InotifyEvent(event->name, FileObjectStatus::MODIFY, 1));
                } else {
                    printf( "The file %s was modified with WD %d\n", event->name, event->wd );
                    Events.push(InotifyEvent(event->name, FileObjectStatus::MODIFY, 0));
                }
            }
            if ( event->mask & IN_DELETE_SELF) {
                if (event->mask & IN_ISDIR) {
                    printf( "The directory %s was deleted.\n", event->name );
                    Events.push(InotifyEvent(event->name, FileObjectStatus::DELETE, 1));
                } else {
                    printf( "The file %s was deleteed with WD %d\n", event->name, event->wd );
                    Events.push(InotifyEvent(event->name, FileObjectStatus::DELETE, 0));
                }
            }
            
                i += EVENT_SIZE + event->len;
            }
        }
    }
    /* Освобождение ресурсов*/
    inotify_rm_watch( fd, wd );
    close( fd );
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

std::string Watcher::readEventsFromBuffer() {
    std::string events;
    InotifyEvent event;
    while (!Events.empty()) {
        event = Events.front();
        events += event.fileObjectName + " " + std::to_string(event.status) + " " + std::to_string(event.is_dir) + "\n";
    }
    return events;
}