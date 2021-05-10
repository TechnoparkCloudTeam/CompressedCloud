#include "Indexer.h"
#include "Watcher.h"
#include "Chunker.h"
#include "ProgramInterface.h"
#include "Application.h"

#include "LocalDB.h"

int main()
{

	UserDB DB("base.dblite");
	DB.exec(R"(
CREATE TABLE IF NOT EXISTS "User" (
	"userId"	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
	"login"	TEXT NOT NULL,
	"password"	TEXT NOT NULL,
	"deviceId"	INTEGER NOT NULL,
	"deviceName"	INTEGER NOT NULL,
	"synchFolder"	TEXT NOT NULL,
	"lastUpdate"	TEXT NOT NULL);                  
)");

	return 0;
}
