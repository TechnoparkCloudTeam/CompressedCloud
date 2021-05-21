//#include "Indexer.h"
//#include "Chunker.h"
#include "ProgramInterface.h"
#include "Application.h"
#include "WatcherNotifierBuilder.h"
#include "ClientNetwork.h"
#include <filesystem>
#include <thread>
#include <boost/thread.hpp>

int main()
{	
	std::shared_ptr<FileDB> fileDBPtr(new FileDB("file.dblite"));
	std::shared_ptr<UserDB> userDBPtr(new UserDB("users.dblite"));
	boost::asio::io_service io_service;
	std::shared_ptr<ClientNetwork> clientNetworkPtr(new ClientNetwork(io_service));
	boost::thread t(boost::bind(&boost::asio::io_service::run, &io_service));

	std::shared_ptr<Application> appPtr(new Application(clientNetworkPtr, userDBPtr, fileDBPtr));
	ProgramInterface console(appPtr);   
	//std::thread thread([&]() { appPtr->runWatcher(); });
	console.run();
	t.join();
	//thread.join();
	return 0;
}