#pragma once
#include <boost/bimap.hpp>
#include <atomic>
#include <assert.h>
#include <vector>
#include <time.h>
#include <thread>
#include <sys/inotify.h>
#include <sys/epoll.h>
#include <string>
#include <sstream>
#include <queue>
#include <optional>
#include <memory>
#include <map>
#include <filesystem>
#include <exception>
#include <errno.h>
#include <chrono>
#include <optional>
#include "FileSysEvent.h"
#include "WatcherConfig.h"

using timePoint = std::chrono::steady_clock::time_point;
using fsPath = std::filesystem::path;
using std::chrono::milliseconds;
using std::string;
using std::vector;
using std::queue;
using boost::bimap;
using std::function;
using steadyClock = std::chrono::steady_clock;
namespace fs = std::filesystem;
using std::stringstream;
class Watcher {
public:
	Watcher();
	~Watcher();
	void watchDirRecursive(fsPath path);
	void watchFile(fsPath file);
	void unwatchFile(fsPath file);
	void ignoreFileOnce(fsPath file);
	void ignoreFile(fsPath file);
	void setEventMask(uint32_t eventMask);
	uint32_t getEventMask();
	void setEventTimeout(milliseconds eventTimeout, function<void(FileSysEvent)> onEventTimeout);
	std::optional<FileSysEvent> getNextEvent();
	void shutDown();
	bool isStopped();
	void runAfterShutDown();
private:
	fsPath wdToPath(int watchDescriptor);
	bool isIgnored(std::string file);
	bool isOnTimeout(const steadyClock::time_point &eventTime);
	void removeWatch(int watchDescriptor);
	ssize_t readEventsIntoBuffer(vector<uint8_t>& eventBuffer);
	void readEventsFromBuffer(uint8_t* buffer, int length, vector<FileSysEvent> &events);
	void filterEvents(vector<FileSysEvent>& events, queue<FileSysEvent>& eventQueue);
	void sendStopSignal();
	int mError;
	milliseconds mEventTimeout;
	timePoint mLastEventTime;
	uint32_t mEventMask;
	uint32_t mThreadSleep;
	vector<string> mIgnoredDirs;
	vector<string> mOnceIgnoredDirs;
	queue<FileSysEvent> mEventQueue;
	bimap<int, fsPath> mDirectoriesMap;
	int mInotifyFileDescriptor;
	std::atomic<bool> mStopped;
	int mEpollFd;
	epoll_event mInotifyEpollEvent;
	epoll_event mStopPipeEpollEvent;
	epoll_event mEpollEvents[MAX_EPOLL_EVENTS];

	function<void(FileSysEvent)> mOnEventTimeout;
	vector<uint8_t> mEventBuffer;

	int StopPipeFileDescriptor[2];
	const int mPipeReadIdx;
	const int mPipeWriteIdx;
};