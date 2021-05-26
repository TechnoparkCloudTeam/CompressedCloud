//#include "Indexer.h"
//#include "Chunker.h"
#include "ProgramInterface.h"
#include "Application.h"
#include "WatcherNotifierBuilder.h"
#include "ClientNetwork.h"
#include <filesystem>
#include <thread>
#include <boost/thread.hpp>
#include "PatternWatcher.h"
int main()
{	
	std::shared_ptr<PatternWatcher> PWPtr(new PatternWatcher());
	std::shared_ptr<FileDB> fileDBPtr(new FileDB("file.dblite"));
	std::shared_ptr<UserDB> userDBPtr(new UserDB("users.dblite"));
	boost::asio::io_service io_service;
	std::shared_ptr<ClientNetwork> clientNetworkPtr(new ClientNetwork(io_service, PWPtr));
	boost::thread t(boost::bind(&boost::asio::io_service::run, &io_service));
	std::shared_ptr<Application> appPtr(new Application(clientNetworkPtr, userDBPtr, fileDBPtr, PWPtr));
	ProgramInterface console(appPtr);   
	console.run();
	std::cout << "\n\nExiting interface\n\n";
	//t.join();
	std::cout << "\n\nNetwork finished";
	return 0;
}