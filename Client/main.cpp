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
	std::shared_ptr<IRequestCoordinator> RequestProccessorPtr(new RequestCoordinator());
	std::shared_ptr<IFileDB> fileDBPtr(new FileDB("file.dblite"));
	std::shared_ptr<IUserDB> userDBPtr(new UserDB("users.dblite"));
	std::shared_ptr<IIndexer> indexerPtr(new Indexer(fileDBPtr, userDBPtr));
	boost::asio::io_service io_service;
	std::shared_ptr<IClientNetwork> clientNetworkPtr(new ClientNetwork(io_service, RequestProccessorPtr));
	boost::thread t(boost::bind(&boost::asio::io_service::run, &io_service));
	std::shared_ptr<Application> appPtr(new Application(clientNetworkPtr, indexerPtr , RequestProccessorPtr));
	std::shared_ptr<IProgramInterface> console(new ProgramInterface(appPtr));
	console->run();
	//t.join();
	return 0;
}
