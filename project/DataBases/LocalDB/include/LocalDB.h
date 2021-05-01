#pragma once
//#include <sqlite3.h>
#include <string>
#include <vector>

class LocalDB {
public:
        bool connect();
        void disconnect();
        void createTable();
        const std::string processRequest(const std::string &query);
        void deleteInfo(const std::string &query);
private:
	std::string nameDB;
	//std::sqlite3 dataBase;
};
