#include "Indexer.h"
//#include "Watcher.h"
//#include "Chunker.h"
#include "ProgramInterface.h"
#include "Application.h"

int main()
{
	Watcher watch;
	std::shared_ptr<Watcher> watchPtr(&watch);

	//UserDB DB1("base.dblite");
	//std::shared_ptr<UserDB> userDBPtr(&DB1);

	Indexer index;
	std::shared_ptr<I_Indexer> indexPtr(&index);

	ClientNetwork clientNet;
	std::shared_ptr<ClientNetwork> clientNetworkPtr(&clientNet);

	std::string path = "";
	FileStorageWorker fileWorker(path);
	std::shared_ptr<FileStorageWorker> fileWorkerPtr(&fileWorker);
	
	//watch.run("/home/ilya/TechnoparkProjects/CompressedCloud/project/Client/testDir");

	Application app(watchPtr, indexPtr, clientNetworkPtr);
	app.setSyncFolder("/home/ilya/TechnoparkProjects/CompressedCloud/project/Client/build/UserWatchedDir");
	std::shared_ptr<Application> appPtr(&app);
	ProgramInterface console(appPtr);

/* 	UserDB DB("base1.dblite");
        DB.exec(R"(
CREATE TABLE IF NOT EXISTS "User" (
	"userId"	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
	"login"	TEXT NOT NULL,
	"password"	TEXT NOT NULL,
	"deviceId"	INTEGER NOT NULL,
	"deviceName"	INTEGER NOT NULL,
	"synchFolder"	TEXT NOT NULL,
	"lastUpdate"	TEXT NOT NULL);                  
)",0,0);

  {
   User user;
   user.userId = 46;
   user.login = "dsagfkshsgrth";
   user.password = "ffgerkheaghf";
   user.deviceId = 27;
   user.deviceName = "kdgrtuurufj";
   user.synchFolder = "lrshtgh";
   user.lastUpdate = "vshvgrurjukej";

    DB.addUser(user);
    std::cout << DB.getUserId(user) << std::endl;
    DB.deleteUser(47);
    std::cout << DB.selectUserId();
  } */
	//console.run();
	
	return 0;
}
