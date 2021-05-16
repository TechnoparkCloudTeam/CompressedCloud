#include "LocalDB.h"
#include "boost/log/trivial.hpp"
#include <utility>
#include <iostream>

/*LocalDB::LocalDB(std::string nameDB): _nameDB(std::move(nameDB)) {
};
*/
/*bool UserDB::connect() {
  auto pDB = _database.get();
  if (SQLITE_OK != sqlite3_open_v2(_userNameDB.c_str(), &pDB, SQLITE_OPEN_CREATE | SQLITE_OPEN_READWRITE, nullptr)) {
                BOOST_LOG_TRIVIAL(error) << "LocalDB can't connect";
                return false;
                }
  _database.reset(pDB);
  BOOST_LOG_TRIVIAL(debug) << "LocalDB connect";
  return true;
}*/

bool UserDB::connect(const std::string_view userNameDB)
  {
    auto pDB = _database.get();
    if (SQLITE_OK != sqlite3_open_v2(userNameDB.data(), &pDB, SQLITE_OPEN_CREATE | SQLITE_OPEN_READWRITE, nullptr))
    {
        BOOST_LOG_TRIVIAL(error) << "LocalDB can't connect\n";
        return false;
    }

    _database.reset(pDB);
     BOOST_LOG_TRIVIAL(debug)  << "LocalDB connect\n";
  
    return true;
  }


UserDB::UserDB(const std::string_view userNameDB)
  {
    if (connect(userNameDB)) 
    {
      //createTable();
    	//_userId = selectUserId();
    	//disconnect();
      //
    }
  }

  
bool UserDB::exec(const std::string_view sql)
  {
    if(!(_database)) return false;
    char *err = 0;
 
    if (sqlite3_exec(_database.get(), sql.data(), 0, 0, &err))
    {
      fprintf(stderr, "Ошибка SQL: %sn", err);
      sqlite3_free(err);
      return false;
    }
    return true;
  }

bool UserDB::addUser(const User& user)
  {
    //if(!_database)return false;
    const std::string query = "INSERT INTO User ("
    //"userId,"
    " login, password, deviceId, deviceName, synchFolder, lastUpdate) VALUES ("
    //+ std::to_string(user.userId)  + ", "
    "'" + user.login + "', " 
    "'" + user.password + "', " 
    "'" + std::to_string(user.deviceId) + "'," 
    "'" + user.deviceName + "'," 
    "'" + user.synchFolder + "'," 
    "'" + user.lastUpdate + "'"
    ")"
    ;

    return exec(query.data());
  }



void UserDB::disconnect() {
  BOOST_LOG_TRIVIAL(debug) << "LocalDB close";
  sqlite3_shutdown();
}

/*void UserDB::createTable() {
  char *err = 0;
  auto pStmt = _stmt.get();
  std::cout <<  "Table will creates    " << createQueryUser.c_str();
  //sqlite3_prepare(_database.get(), createQueryUser.c_str(), createQueryUser.size(), &pStmt, nullptr);
  if(sqlite3_exec(_database.get(), createQueryUser.c_str(), 0, 0, &err)) {
  fprintf(stderr, "Ошибка SQL: %sn", err);
  sqlite3_free(err);
  }
  //_stmt.reset(pStmt);
  if(sqlite3_step(_stmt.get()) != SQLITE_DONE) {
  std::string error = "LocalDB didn't create table";
  BOOST_LOG_TRIVIAL(error) << error;
  }
  BOOST_LOG_TRIVIAL(debug) << "UserDB created";

}*/

/*int UserDB::selectId(const std::string& query) {
  int id = -1;
  auto pStmt = _stmt.get();
  sqlite3_prepare_v2(_database.get(), query.c_str(), query.size(), &pStmt, nullptr);
  _stmt.reset(pStmt);
  while(sqlite3_step(_stmt.get()) == SQLITE_ROW) {
	id = sqlite3_column_int(_stmt.get(), 0);
	BOOST_LOG_TRIVIAL(debug) << "LocalDB: Selected";
  }
  return  id;
}*/

/*
const std::string LocalDB::processRequest(const std::string &query) {
}
*/

/*UserDB::UserDB(const std::string_view userNameDB): _userNameDB(userNameDB) {
 if (connect()) {
    createTable();
	//_userId = selectUserId();
	//disconnect();
  }
        
};*/

int UserDB::getUserId(const User& user) {
        return user.userId;
}

/*void UserDB::add(const std::string &query) {
  auto pStmt = _stmt.get();
  std::cout << "Beginning of add query.c_str()       " << query.c_str();
  sqlite3_prepare_v2(_database.get(), query.c_str(), query.size(), &pStmt, nullptr);
  _stmt.reset(pStmt);
  const auto res=sqlite3_step(_stmt.get());
  std::cout<< "in method add      " << res;
  if ( res != SQLITE_DONE) {
  std::string error = "UserDB didn't add";
	BOOST_LOG_TRIVIAL(error) << error;
  }
  BOOST_LOG_TRIVIAL(debug) << "LocalDB: added";

}*/
/*
voidLOcalDB::selectId(const std::string &query) {
}
*/
/*void UserDB::addUser(const User& user) {
     std::string query = "INSERT INTO User (userId, login, password, deviceId, deviceName, synchFolder, lastUpdate) VALUES ("+ std::to_string(user.userId)+ ", '" + user.login+ "', '" + user.password+"', " + std::to_string(user.deviceId)+ ", '" + user.deviceName+ "', '" + user.synchFolder+ "', '" + user.lastUpdate+ "');";;
        add(query);
       // disconnect();
}*/

void UserDB::deleteUser(int id) {
        std::string query = "DELETE FROM User WHERE user_id = " + std::to_string(id) + ";";
        exec(query.data());

        BOOST_LOG_TRIVIAL(debug) << "User deleted";
       // disconnect();

}

int UserDB::selectUserId() {
         const std::string query = "SELECT userId FROM User:";
         int id = exec(query.data());
         return id;
}

/*void test() {
 //UserDB userDB("UserDB.db3");
  std::string dbname="UserDB.db3";

  sqlite3* pDB{};
  std::unique_ptr<sqlite3_stmt, sqlite3_stmt_deleter> Stmt;

#if 1

 // pDB->connect();


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
  auto temp_smtp=Stmt.get();
  sqlite3_prepare(pDB, createQueryUser.c_str(), createQueryUser.size(), &temp_smtp, nullptr);
  Stmt.reset(temp_smtp);

  if(sqlite3_step(&*Stmt) != SQLITE_DONE) {
    std::string error = "LocalDB didn't create table";
    BOOST_LOG_TRIVIAL(error) << error;
  }
  BOOST_LOG_TRIVIAL(debug) << "UserDB created";

  BOOST_LOG_TRIVIAL(debug) << "LocalDB close";
  sqlite3_shutdown();



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
#endif
}


void ChunkDB::addChunks(const Chunks& chunks) {
  std::string query = "INSERT INTO Chunks (idFile) VALUES (" + std::to_string(chunks.idFile) + ");";
  add(query);
}
*/
/*void FileDB::addFile(FileMeta &file) {
  BOOST_LOG_TRIVIAL(debug) << "FileDB: Insert File";
	std::string query = "INSERT INTO Files (id, fileName, fileSize, version, quantityChunks) VALUES ('" + file.fileName + "', " + std::to_string(file.fileSize) + ", " + std::to_string(file.version) + ", '" + std::to_string(file.quantityChunks) + "');";
	localDB.add(query);
  localDB.disconnect();
}
*/

