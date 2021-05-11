#include "Indexer.h"
#include "Watcher.h"
//#include "Chunker.h"
#include "ProgramInterface.h"
#include "Application.h"
#include "LocalDB.h"

int main()
{
	Watcher watch;
	std::shared_ptr<Watcher> watchPtr(&watch);

	UserDB DB("base.dblite");
	std::shared_ptr<UserDB> userDBPtr(&DB);

	Indexer index(userDBPtr);
	std::shared_ptr<I_Indexer> indexPtr(&index);

	ClientNetwork clientNet;
	std::shared_ptr<ClientNetwork> clientNetworkPtr(&clientNet);

	std::string path = "";
	FileStorageWorker fileWorker(path);
	std::shared_ptr<FileStorageWorker> fileWorkerPtr(&fileWorker);
	
	//watch.run("/home/ilya/TechnoparkProjects/CompressedCloud/project/Client/testDir");

	Application app(watchPtr, indexPtr, clientNetworkPtr);

	std::shared_ptr<Application> appPtr(&app);
	ProgramInterface console(appPtr);

	console.run();
	return 0;
}
