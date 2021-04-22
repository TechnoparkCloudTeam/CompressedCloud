#pragma once
#include <cstdint>
#include <filesystem>
#include <vector>
enum Event : uint32_t {

};

struct InotifyEvent {
	std::filesystem::path Path;
	Event event;
};

class IWatcher {
public:
	virtual void run(std::filesystem::path Path) = 0;
	virtual void shutdown() = 0;
	virtual bool isWorking() = 0;
};

class Watcher : public IWatcher {
public:
	void run(std::filesystem::path Path) override;
	void shutdown() override;
	bool isWorking() override;
	void readEventsFromBuffer();
private:
	void SetEventMask(uint32_t EventMask);
	void AddFileToWatch(std::filesystem::path Path);
	void AddDirToWatch();
	void RemoveDirFromWatch();
	void RemoveFileFromWatch();
	void WriteEventsToBuffer();
	std::vector<int8_t> buffer;
	std::filesystem::path WorkDir;
	uint32_t EventMask;
	bool working;
};