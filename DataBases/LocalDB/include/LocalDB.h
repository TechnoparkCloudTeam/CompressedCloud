#pragma once
#include <memory>
#include <string>
#include <sqlite3.h>
#include <functional>
#include <vector>
#include <ctime>
#include <optional>

#include "IFileDB.h"
#include "IUserDB.h"

class UserDB : public IUserDB
{
public:
	UserDB(const std::string_view userNameDB);

	bool exec(const std::string_view sql,
			  std::function<int(const s_record &r, void *context)> record_callback = nullptr //retuen false to continue enumeration
			  ,
			  void *context = nullptr) override;

	bool connect(const std::string_view userNameDB) override;

	void disconnect() override;

	void createTable() override;

	bool addUser(const User &user) override;

	void deleteUser(int id) override;

	bool isUserExist(const int &userId) override;

	int getUserId(const std::string &login) override;

	int getDeviceId(const User &user) override;

	std::string getLogin(const User &user) override;

	int getPassword(const User &user) override;

	std::string getSynchFolder(const User &user) override;

	std::string getLastUpdate(User &user) override;

	int selectUserId() override;

	int selectDeviceId() override;

	int selectLogin() override;

	bool selectPassword(const User &user) override;

	int selectFolder() override;

	int selectLastUpdate() override;

	bool updateSynchFolder(User &user, const std::string &newFolder) override;

	bool updatePassword(User &user, const std::string &newPassword) override;

	void saveLastUpdate(User &user) override;

private:
	std::unique_ptr<sqlite3, sqlite3_deleter> _database;
};

class FileDB : public IFileDB
{
public:
	FileDB(const std::string_view fileNameDB);

	bool exec(const std::string_view sql,
			  std::function<int(const s_record &r, void *context)> record_callback = nullptr //retuen false to continue enumeration
			  ,
			  void *context = nullptr) override;

	bool connect(const std::string_view fileNameDB) override;

	void disconnect() override;

	void createTable() override;

	void addFile(FileMeta &file) override;

	void deleteFile(const std::string &fileName, const std::string &filePath) override;

	void downloadFile(const int &fileId) override;

	bool isFileExist(const int &fileId) override;

	std::optional<FileMeta> getOneFile(const int id) override;

	int selectId() override;

	int selectFileId() override;

	/*    FileMeta selectFile(const int &fileId) override; */

	std::vector<FileMeta> selectAllFiles() override;

	void updateFile(FileMeta &file) override;

	static std::time_t getTime_unixtime();

private:
	std::unique_ptr<sqlite3, sqlite3_deleter> _database;
};
