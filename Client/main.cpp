#include "Indexer.h"
#include "ProgramInterface.h"
#include "Application.h"
#include "WatcherNotifierBuilder.h"
#include "ClientNetwork.h"
#include "RequestCoordinator.h"

#include <filesystem>
#include <thread>
#include <boost/thread.hpp>
#include <algorithm>

int main()
{	
	std::shared_ptr<RequestCoordinator> RequestProccessorPtr(new RequestCoordinator());
	std::shared_ptr<FileDB> fileDBPtr(new FileDB("file.dblite"));
	std::shared_ptr<UserDB> userDBPtr(new UserDB("users.dblite"));
	std::shared_ptr<Indexer> indexerPtr(new Indexer(fileDBPtr, userDBPtr));
	boost::asio::io_service io_service;
	std::shared_ptr<ClientNetwork> clientNetworkPtr(new ClientNetwork(io_service, RequestProccessorPtr));
	boost::thread t(boost::bind(&boost::asio::io_service::run, &io_service));
	std::shared_ptr<Application> appPtr(new Application(clientNetworkPtr, indexerPtr , RequestProccessorPtr));
	ProgramInterface console(appPtr);   
	console.run();
	std::cout << "\n\nExiting interface\n\n";
	//t.join();
	std::cout << "\n\nNetwork finished";
	return 0;
}
