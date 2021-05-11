#pragma once
#include <cstdint>
#include <filesystem>
#include <vector>
#include <sys/inotify.h>
#include <unistd.h>
#include "WatcherConfig.h"
#include <iostream>
#include <string>
struct InotifyEvent {
	std::filesystem::path Path;
	//Event event;
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
	void readEventsFromBuffer();
private:
	void SetEventMask(uint32_t EventMask);
	void AddFileToWatch(std::string Path);
	void AddDirToWatch();
	void RemoveDirFromWatch();
	void RemoveFileFromWatch();
	void WriteEventsToBuffer();
	char buffer[BUFFER_LEN];
	std::filesystem::path WorkDir;
	uint32_t EventMask;
	bool working;
};