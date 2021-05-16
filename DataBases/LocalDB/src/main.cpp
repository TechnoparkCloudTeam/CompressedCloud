#include <iostream>
#include "LocalDB.h"
#include <vector>
#include "boost/log/trivial.hpp"
#include <sqlite3.h>

int main(int argc, char **argv) {
       // test();
  //UserDB userDB("UserDB.db3");
 /* std::string dbname="UserDB.db3";

  sqlite3* pDB{};
  sqlite3_smtp* pStmt{};

#if 1
  if (SQLITE_OK != sqlite3_open_v2(dbname.c_str(), &pDB, SQLITE_OPEN_CREATE | SQLITE_OPEN_READWRITE, nullptr)) {
                BOOST_LOG_TRIVIAL(error) << "LocalDB can't connect";
                return false;
                }

  std::string createQueryUser=R"(
CREATE TABLE IF NOT EXISTS "User" (
	"userId"	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
	"login"	TEXT NOT NULL,
	"password"	TEXT NOT NULL,
	"deviceId"	INTEGER NOT NULL,
	"deviceName"	INTEGER NOT NULL,
	"synchFolder"	TEXT NOT NULL,
	"lastUpdate"	TEXT NOT NULL);                  
)";

    std::cout <<  "Table will creates    " << createQueryUser.c_str();
  sqlite3_prepare(pDB, createQueryUser.c_str(), createQueryUser.size(), &pStmt, nullptr);

  if(sqlite3_step(pStmt) != SQLITE_DONE) {
    std::string error = "LocalDB didn't create table";
    BOOST_LOG_TRIVIAL(error) << error;
  }
  BOOST_LOG_TRIVIAL(debug) << "UserDB created";

  //userDB.disconnect();
  //userDB.deleteUser(50);
  //std::cout << "Deleted User /n/n/n/n/n/n/n";
  User u;
  u.userId = 46;
  u.login = "dsagfkshsgrth";
  u.password = "ffgerkheaghf";
  u.deviceId = 27;
  u.deviceName = "kdgrtuurufj";
  u.synchFolder = "lrshtgh";
  u.lastUpdate = "vshvgrurjukej";
  userDB.addUser(u);
#endif*/

 /* UserDB DB("UserDB.dblite");
    DB.exec(R"(
CREATE TABLE IF NOT EXISTS "User" (
	"userId"	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
	"login"	TEXT NOT NULL,
	"password"	TEXT NOT NULL,
	"deviceId"	INTEGER NOT NULL,
	"deviceName"	INTEGER NOT NULL,
	"synchFolder"	TEXT NOT NULL,
	"lastUpdate"	TEXT NOT NULL);                  
)");*/
  /*  {
   User user;
  // user.userId = 46;
   user.login = "dsagfkshsgrth";
   user.password = "ffgerkheaghf";
   user.deviceId = 27;
   user.deviceName = "kdgrtuurufj";
   user.synchFolder = "lrshtgh";
   user.lastUpdate = "vshvgrurjukej";

    DB.addUser(user);
  }
*/

  /*User u;
  u.userId = 46;
  u.login = "dsagfkshsgrth";
  u.password = "ffgerkheaghf";
  u.deviceId = 27;
  u.deviceName = "kdgrtuurufj";
  u.synchFolder = "lrshtgh";
  u.lastUpdate = "vshvgrurjukej";
  DB.addUser(u);
*/

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

  {
   User user;
  // user.userId = 46;
   user.login = "dsagfkshsgrth";
   user.password = "ffgerkheaghf";
   user.deviceId = 27;
   user.deviceName = "kdgrtuurufj";
   user.synchFolder = "lrshtgh";
   user.lastUpdate = "vshvgrurjukej";

    DB.addUser(user);
  }



  return 0;
}

