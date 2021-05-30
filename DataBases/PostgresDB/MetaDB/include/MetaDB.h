#pragma once

#include <vector>
#include <string>
#include "PostgreSQLDB.h"
#include "PostgresExceptions.h"
#include "FileInfo.h"
#include "UserDate.h"

class MetaDataDB : public PostgresSQLDB {
 protected:
 public:
  ~MetaDataDB() override = default;
  static MetaDataDB &shared(std::string_view info);
  void createTable();
  void InsertFile(const FileMeta &fileMeta);
  std::vector<FileInfo> GetUserFilesByTime(const UserDate &userDate);
  bool isFileExist(std::string login);
  void deleteFile(std::string login, std::string fileName);
  std::string GetFile(std::string login);

 private:
  explicit MetaDataDB(std::string_view info);
  MetaDataDB(const MetaDataDB &mongo_db);
  MetaDataDB &operator=(const MetaDataDB &mongo_db);

  static std::string getTime(std::string &time);
  int getLastIdOfFileUser(const std::string &query, PostgresExceptions exceptions);
};

