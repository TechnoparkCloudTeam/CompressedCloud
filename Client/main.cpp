//#include "Indexer.h"
//#include "Chunker.h"
#include "ProgramInterface.h"
#include "Application.h"
#include "WatcherNotifierBuilder.h"
#include <filesystem>
#include <thread>
#include "ClientNetwork.h"
#include <boost/thread.hpp>

std::string GetCurrentPath()
{
	std::filesystem::path Path = std::filesystem::current_path();
	return Path.c_str();
}

std::string GetCurrentTime()
{
	auto ttime = time(nullptr);
	auto *local_time = localtime(&ttime);
	std::string lastTMPUpdate = std::to_string(1900 + local_time->tm_year) + "-" + std::to_string(1 + local_time->tm_mon) + "-" + std::to_string(local_time->tm_mday) + " " + std::to_string(local_time->tm_hour) + ":" + std::to_string(local_time->tm_min) + ":" + std::to_string(local_time->tm_sec);
	return lastTMPUpdate;
}

bool isTmpFile(const std::string& fileName) {
	return (fileName.find(".goutputstream") == std::string::npos);
}

int main()
{
 
	std::string dirName = "/home/ilya/test";

	std::shared_ptr<UserDB> userDBPtr(new UserDB("base.dblite"));

	std::shared_ptr<FileDB> fileDBPtr(new FileDB("file.dblite"));

	boost::asio::io_service io_service;
	std::shared_ptr<ClientNetwork> clientNetworkPtr(new ClientNetwork(io_service));
	boost::thread t(boost::bind(&boost::asio::io_service::run, &io_service));


	std::shared_ptr<FileStorageWorker> fileWorkerPtr(new FileStorageWorker(""));
	
	std::shared_ptr<Application> appPtr(new Application(clientNetworkPtr, userDBPtr, fileDBPtr));
	ProgramInterface console(appPtr);   

	

	console.run();


	auto handleNotification = [&](WatcherNotification notification)
	{
		std::cout << "Event " << notification.Event << " on " << notification.Path << " at "
				  << notification.Time.time_since_epoch().count() << " was triggered.\n";

		FileMeta f;
		f.fileName = notification.Path.filename();
		f.fileExtention = notification.Path.extension();
		f.createDate = GetCurrentTime();
		f.updateDate = GetCurrentTime();
		f.isDownload = false;
		f.version = 1;
		f.chunksCount = 0;
		f.filePath = "desktop";
		f.fileSize = 232;
		switch (notification.Event)
		{
		case InotifyEvent::_create:
		{
			if (isTmpFile(notification.Path.filename())) {
				//fileDB.addFile(f);
				//fileDB.updateFile(f);
			}
			break;
		}
		case InotifyEvent::_modify:
		{
			if (isTmpFile(notification.Path.filename())) {
				//fileDB.updateFile(f);
			}
			break;
		}
		case InotifyEvent::_remove:
		{
			if (isTmpFile(notification.Path.filename())) {
				//fileDB.deleteFile(f.fileId);
			}
			break;
		}
		default:
			break;
		}
	};

	auto handleUnexpectedNotification = [](WatcherNotification notification)
	{
		//std::cout << "Event " << notification.Event << " on " << notification.Path << " at " << notification.Time.time_since_epoch().count() << " was triggered, but was not expected.\n";
	};

	auto events = {InotifyEvent::_open | InotifyEvent::_is_dir,
				   InotifyEvent::_access,
				   InotifyEvent::_create,
				   InotifyEvent::_modify,
				   InotifyEvent::_remove,
				   InotifyEvent::_move};

	auto notifier = BuildWatcherNotifier()
						.watchPathRecursively(dirName)
						.ignoreFileOnce("fileIgnoredOnce")
						.onEvents(events, handleNotification)
						.onUnexpectedEvent(handleUnexpectedNotification);

	std::thread thread([&]()
					   { notifier.run(); });

	//std::this_thread::sleep_for(std::chrono::seconds(60));


	t.join();
	thread.join();
	return 0;
}
