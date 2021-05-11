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
  void InsertFile(const FileInfo &fileMeta);
  std::vector<FileInfo> GetUserFilesByTime(const UserDate &userDate);

 private:
  explicit MetaDataDB(std::string_view info);
  MetaDataDB(const MetaDataDB &mongo_db);
  MetaDataDB &operator=(const MetaDataDB &mongo_db);

  static std::string getTime(std::string &time);
  int getLastIdOfFileUser(const std::string &query, PostgresExceptions exceptions);
};

