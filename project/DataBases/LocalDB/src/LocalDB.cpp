#include "LocalDB.h"
#include "boost/log/trivial.hpp"
#include <utility>
#include "UserDB.h"

LocalDB::LocalDB(std::string nameDB): nameDB(std::move(nameDB)) {
}

bool LocalDB::connect() {
  sqlite3 **pDB = database.get();
  if (SQLITE_OK != sqlite3_open_v2(nameDB.c_str(), &pDB, SQLITE_OPEN_CREATE | SQLITE_OPEN_READWRITE, nullptr) {
                BOOST_LOG_TRIVIAL(error) << "LocalDB can't connect";
                return false;
                }
  database.reset(pDB);
  BOOST_LOG_TRIVIAL(debug) << "LocalDB connect";
  return true;
}

void LocalDB::disconnect() {
  BOOST_LOG_TRIVIAL(debug) << "LocalDB close";
  sqlite3_shutdown();
}

void LocalDB::createTable() {
  sqlite3_stmt **pStmt = stmt.get();
  sqlite3_prepare(database.get(), /* ??? */, /* ??? */, &pStmt, nullptr);
  stmt.reset(pStmt);
  if(sqlite3_step(stmt.get()) != SQLITE_DONE) {
  std::string error = "LocalDB didn't create table";
  BOOST_LOG_TRIVIAL(error) << error;
  }
}

const std::string LocalDB::processRequest(const std::string &query) {
}

int UserDB::getUserId() {
        return userId;
}

void UserDB::addUser(const User& user) {
        std::string query = "INSERT INTO User (userId, login, password, deviceId, deviceName, synchFolder, lastUpdate) VALUES ("+ std::to_string(user.userId) + ", " + user.login, + ", " +user.password + ", " + std::to_string(user.deviceId) + ", " + user.deviceName + ", " + user.synchFolder + ", " + user.lastUpdate + ");";
}

void UserDB::deleteUser(int id) {
        std::string query = "DELETE FROM User WHERE user_id = " + std::to_string(id) + ";";
        sqlite3_stmt **pStmt = stmt.get();
        sqlite3_prepare_v2(database.get, query.c_str(), query.size(), &pStmt, nullptr);
        stmt.rest(pstmt);
        if (sqlite3_step(stmt.get()) != SQLITE_DONE) {
                BOOST_LOG_TRIVIAL(error) << "User didn't delete";
        }
        BOOST_LOG_TRIVIAL(debug) << "User deleted";
}

int UserDB::selectUserId() {
        std::string query = "SELECT userId FROM User:";
        int id = selectId(query);
        return id;
}
