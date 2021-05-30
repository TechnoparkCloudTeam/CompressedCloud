#pragma once
#include "FileDB.h"
#include <memory>
#include <string>
#include <sqlite3.h>
#include "UserDB.h"
#include <functional>
#include <vector>
#include <ctime>
#include <optional>

struct sqlite3_deleter {
  void operator()(sqlite3* sql) {
	sqlite3_close_v2(sql);
  }
};

struct s_column
{
   std::string col_name;
   std::string col_text;
};

struct s_record:public std::vector<s_column>
{
};
							   
class UserDB {
public:
	UserDB(const std::string_view  userNameDB);
	
	bool exec(const std::string_view sql,
                std::function<int(const s_record& r,void* context)> record_callback=nullptr //retuen false to continue enumeration
                ,void* context=nullptr
                );

        bool connect(const std::string_view userNameDB);
        void disconnect();
        void createTable();

	bool addUser(const User &user);
        void deleteUser(int id);
        
        bool isUserExist(const int &userId);
        
        int getUserId(const std::string &login);
  	int getDeviceId(const User& user);
  	std::string getLogin(const User& user);
  	int getPassword(const User& user);
	std::string getSynchFolder(const User& user);
	std::string getLastUpdate(User& user);
	 
	int selectUserId();
        int selectDeviceId();
 	int selectLogin();
  	bool selectPassword(const User& user);
  	int selectFolder();
  	int selectLastUpdate();
  	
        bool updateSynchFolder(User& user, const std::string &newFolder);
        bool updatePassword(User& user, const std::string &newPassword);
        
        void saveLastUpdate(User& user);
private:
        std::unique_ptr<sqlite3, sqlite3_deleter> _database;
};

class FileDB {
public:
	FileDB(const std::string_view  fileNameDB);
	
	bool exec(const std::string_view sql,
                std::function<int(const s_record& r,void* context)> record_callback=nullptr //retuen false to continue enumeration
                ,void* context=nullptr
                );
	
	bool connect(const std::string_view fileNameDB);
	void disconnect(); 
	void createTable();
	
	void addFile(FileMeta &file);
        void deleteFile(const std::string &fileName, const std::string &filePath); 
        void downloadFile(const int &fileId);
	
	bool isFileExist(const int &fileId);

        std::optional<FileMeta> getOneFile(const int id);
        
        static std::time_t getTime_unixtime();
        
        int selectId();
        int selectFileId();
        FileMeta selectFile(const int &fileId);
        std::vector<FileMeta> selectAllFiles();
        
        void updateFile(FileMeta &file);
        
private:
       std::unique_ptr<sqlite3, sqlite3_deleter> _database;   
};
