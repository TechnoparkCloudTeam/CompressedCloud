#pragma once

#include <vector>
#include <string>
#include "PostgresExceptions.h"

#include "IMetaDB.h"

class MetaDataDB : public IMetaDataDB
{
protected:
public:
	explicit MetaDataDB(std::string_view info);
	~MetaDataDB() override = default;
	static MetaDataDB &shared(std::string_view info);
	void createTable() override;
	void InsertFile(const FileMeta &fileMeta) override;
	std::vector<FileInfo> GetUserFilesByTime(const UserDate &userDate) override;
	bool isFileExist(std::string login) override;
	void deleteFile(std::string login, std::string fileName) override;
	std::string GetFile(std::string login) override;

private:
	MetaDataDB(const MetaDataDB &mongo_db);
	MetaDataDB &operator=(const MetaDataDB &mongo_db);

	static std::string getTime(std::string &time);
	int getLastIdOfFileUser(const std::string &query, PostgresExceptions exceptions);
};
