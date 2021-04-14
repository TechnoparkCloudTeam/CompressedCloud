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
	virtual void AddDirToWatch(std::filesystem::path Path) = 0;
	virtual void SendDirStatus(std::filesystem::path Path) = 0;
	virtual void GetStatus() = 0;
};

class Watcher : public IWatcher {
public:
	void AddDirToWatch(std::filesystem::path Path) override;
	void SendDirStatus(std::filesystem::path Path) override;
	void GetStatus() override;
private:
	void BeginWatch();
	void EndWatch();
	void SetEventMask(uint32_t EventMask);

	void AddFileToWatch(std::filesystem::path Path);
	std::vector<InotifyEvent>& CheckDir(std::filesystem::path Dir);
	InotifyEvent& CheckFile(std::filesystem::path File);
	
	std::filesystem::path WorkDir;
	uint32_t EventMask;
};