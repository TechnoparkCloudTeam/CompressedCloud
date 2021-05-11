#pragma once
#include <cstdint>
#include <filesystem>
#include <vector>
#include <sys/inotify.h>
#include <unistd.h>
#include "WatcherConfig.h"
#include <iostream>
#include <string>
#include <queue>

enum FileObjectStatus : int {
	CREATE = 0,
	MODIFY = 1,
	DELETE = 2
};

struct InotifyEvent {
	std::string fileObjectName;
	FileObjectStatus status;
	bool is_dir;
	InotifyEvent(std::string name = "", FileObjectStatus status = FileObjectStatus::DELETE, bool is_dir = 0) :
		fileObjectName(name),
		status(status),
		is_dir(is_dir) {};
};


class IWatcher {
public:
	virtual void run(std::string Path) = 0;
	virtual void shutdown() = 0;
	virtual bool isWorking() = 0;
};

class Watcher : public IWatcher {
public:
	void run(std::string Path) override;
	void shutdown() override;
	bool isWorking() override;
	std::string readEventsFromBuffer();
private:
	void SetEventMask(uint32_t EventMask);
	void AddFileToWatch(std::string Path);
	void AddDirToWatch();
	void RemoveDirFromWatch();
	void RemoveFileFromWatch();
	void WriteEventsToBuffer();
	char buffer[BUFFER_LEN];
	std::string WorkDir;
	uint32_t EventMask;
	bool working;
	std::queue<InotifyEvent> Events;
};