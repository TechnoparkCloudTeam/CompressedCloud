#include "Indexer.h"
//#include "Watcher.h"
//#include "Chunker.h"
#include "ProgramInterface.h"
#include "Application.h"
#include "WatcherNotifierBuilder.h"
#include <filesystem>
#include <thread>
std::string GetCurrentPath() {
	std::filesystem::path Path = std::filesystem::current_path();
	return Path.c_str();
}

int main()
{
	std::shared_ptr<UserDB> userDBPtr(new UserDB("base.dblite"));

	std::shared_ptr<I_Indexer> indexPtr(new Indexer);

	std::shared_ptr<ClientNetwork> clientNetworkPtr(new ClientNetwork);

	std::shared_ptr<FileStorageWorker> fileWorkerPtr(new FileStorageWorker(""));
	
	std::shared_ptr<Application> appPtr(new Application(indexPtr, clientNetworkPtr));
	ProgramInterface console(appPtr);  


	//console.run();
	
	return 0;
}
