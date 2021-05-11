#include "ChunkDB.h"
#include "FileDB.h"
#include <memory>
#include <string>
#include <sqlite3.h>
#include "UserDB.h"



struct sqlite3_deleter {
  void operator()(sqlite3* sql) {
	sqlite3_close_v2(sql);
  }
};

struct sqlite3_stmt_deleter {
  void operator()(sqlite3_stmt* sql) {
	sqlite3_finalize(sql);
  }
};

/*class LocalDB {
public:
        bool connect();
        void disconnect();
        void createTable();
        const std::string processRequest(const std::string &query);
        void deleteUserInfo(int id);
        void add(const std::string &query);
        int selectId(const std::string& query); 
private:
	explicit LocalDB(std::string  nameDB);
       // std::string nameDB;
        std::unique_ptr<sqlite3, sqlite3_deleter> _database;
  	std::unique_ptr<sqlite3_stmt, sqlite3_stmt_deleter> _stmt;
	std::string _nameDB;
	const std::string createQueryFiles = "CREATE TABLE IF NOT EXISTS  \"Files\" (\n"
							   "\t\"id\"\tINTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,\n"
							   "\t\"file_name\"\tTEXT NOT NULL,\n"
							   "\t\"quantityChunks\"\tINTEGER NOT NULL,\n"
							   "\t\"version\"\tINTEGER NOT NULL,\n"
							   ");";
};

*/

//void test();
									   
class UserDB {
public:
	UserDB(const std::string_view  userNameDB);
	bool connect(const std::string_view userNameDB);
        void disconnect();
        bool exec(const std::string_view sql);
        //void createTable();
        int selectUserId();
        void deleteUser(int id);
        //void add(const std::string &query);
        //int selectId(const std::string& query); 
        int getUserId(const User& user);
        bool addUser(const User &user);
private:
        //LocalDB localDB;
        //int _userId;
        //std::string _userNameDB;
        //User user;
        std::unique_ptr<sqlite3, sqlite3_deleter> _database;
  	//std::unique_ptr<sqlite3_stmt, sqlite3_stmt_deleter> _stmt;
  	const std::string createQueryUser = "CREATE TABLE IF NOT EXISTS \"User\" (\n"
							  "\t\"userId\"\tINTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,\n"
							  "\t\"login\"\tTEXT NOT NULL,\n"
							  "\t\"password\"\tTEXT NOT NULL,\n"
							  "\t\"deviceId\"\tINTEGER NOT NULL,\n"
							  "\t\"deviceName\"\tINTEGER NOT NULL,\n"
							  "\t\"synchFolder\"\tTEXT NOT NULL,\n"
							  "\t\"lastUpdate\"\tTEXT NOT NULL\n"
							  ");";

};

/*class FileDB {
public:
        void renameFile(FileMeta &file);
        void addFile(FileMeta &file);
        void deleteFile(FileMeta &file);
        void updateFile(FileMeta &file);
        FileMeta selectFile(const int &fileId);
        FileMeta getFile(const std::string &path, const std::string &name);
        int getFileId(const std::string &path, const std::string &name);
        std::vector<FileMeta> selectAllFiles();
        void updateSynchFolder(const std::string  &newFolder);
        
        FileMeta fileMeta;
        LocalDB localDB;;
};*/
