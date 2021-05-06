#include "ChunkDB.h"
#include "FileDB.h"
#include "UserDB.h"
#include <memory>
#include <string>
#include <sqlite3.h>

class LocalDB {
public:
        bool connect();
        void disconnect();
        void createTable();
        const std::string processRequest(const std::string &query);
        void deleteUserInfo(int id);
private:
        std::string nameDB;
        std::unique_ptr<LocalDB> database;
  	std::unique_ptr<LocalDB> stmt;
};
