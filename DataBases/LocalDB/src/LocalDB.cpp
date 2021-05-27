#include "LocalDB.h"
#include "boost/log/trivial.hpp"
#include <utility>
#include <iostream>
#include <boost/lexical_cast.hpp>
#include <stdlib.h>

//TODO: Put BOOST_LOG Output in file

UserDB::UserDB(const std::string_view userNameDB)
{
  if (connect(userNameDB))
  {
    createTable();
  }
}

bool UserDB::exec(const std::string_view sql,
                  std::function<int(const s_record &r, void *context)> record_callback, void *context)
{
  if (!(_database))
    return false;
  char *err = 0;

  if (record_callback)
  {
    struct s_local_context
    {
      void *context{};
      std::function<int(const s_record &r, void *context)> record_callback{};
    };

    s_local_context lc{context, record_callback};

    if (sqlite3_exec(
            _database.get(), sql.data(), [/*&record_callback*/](void *context, int cols_count, char **texts_array, char **names_array) {
              s_local_context *lc = reinterpret_cast<s_local_context *>(context);
              s_record r;
              r.reserve(cols_count);
              for (int col = 0; col < cols_count; col++)
              {
                s_column c{names_array[col], texts_array[col]};

                r.emplace_back(c);
              }
              return lc->record_callback(r, lc->context);
            },
            &lc, &err))
    {
      fprintf(stderr, "Ошибка SQLite: %sn", err);
      sqlite3_free(err);
      return false;
    }
  }
  else
  {
    if (sqlite3_exec(_database.get(), sql.data(), 0, 0, &err))
    {
      fprintf(stderr, "Ошибка SQLite: %sn", err);
      sqlite3_free(err);
      return false;
    }
  }
  //std::cout << "Completed successfully and finished working with code ";
  return true;
}

bool UserDB::connect(const std::string_view userNameDB)
{
  auto pDB = _database.get();
  if (SQLITE_OK != sqlite3_open_v2(userNameDB.data(), &pDB, SQLITE_OPEN_CREATE | SQLITE_OPEN_READWRITE, nullptr))
  {
    //BOOST_LOG_TRIVIAL(error) << "UserDB can't connect\n";
    return false;
  }

  _database.reset(pDB);
  //BOOST_LOG_TRIVIAL(debug) << "UserDB connect\n";

  return true;
}

void UserDB::disconnect()
{
  //BOOST_LOG_TRIVIAL(debug) << "UserDB close";
  sqlite3_shutdown();
}

void UserDB::createTable()
{
  //BOOST_LOG_TRIVIAL(debug) << "UserDB: createTable";
  exec(R"(
    CREATE TABLE IF NOT EXISTS "User" (
	  "userId"	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
	  "login"	TEXT NOT NULL unique,
	  "password"	TEXT NOT NULL,
	  "deviceId"	INTEGER NOT NULL,
	  "deviceName"	INTEGER NOT NULL,
	  "synchFolder"	TEXT NOT NULL,
	  "lastUpdate"	TEXT NOT NULL);                  
    )",
       0, 0);
  //BOOST_LOG_TRIVIAL(debug) << "UserDB: Table created";
}

bool UserDB::addUser(const User &user)
{
  //BOOST_LOG_TRIVIAL(debug) << "UserDB: addUser";

  //if(!_database)return false;
  const std::string query = "INSERT INTO User ("
                            //"userId,"
                            " login, password, deviceId, deviceName, synchFolder, lastUpdate) VALUES ("
                            //+ std::to_string(user.userId)  + ", "
                            "'" +
                            user.login + "', "
                                         "'" +
                            user.password + "', "
                                            "'" +
                            std::to_string(user.deviceId) + "',"
                                                            "'" +
                            user.deviceName + "',"
                                              "'" +
                            user.synchFolder + "',"
                                               "'" +
                            user.lastUpdate + "'"
                                              ")";
  //BOOST_LOG_TRIVIAL(debug) << "User added";

  return exec(query.data());
}

void UserDB::deleteUser(int id)
{
  //BOOST_LOG_TRIVIAL(debug) << "UserDB: deleteUser";

  std::string query = "DELETE FROM User WHERE userId = " + std::to_string(id) + ";";
  exec(query.data());

  //BOOST_LOG_TRIVIAL(debug) << "User deleted";
}

bool UserDB::isUserExist(const int &userId)
{
  //BOOST_LOG_TRIVIAL(debug) << "UserDB: isUserExist";

  auto query = "SELECT userId id FROM User where id=" + std::to_string(userId) + ";";
  std::vector<s_record> result;
  int id = exec(
      query.data(), [&result](const s_record &r, void *context) {
        result.emplace_back(r);
        return 0;
      },
      this);

  int count = result.size();

  return count != 0;
}

int UserDB::getUserId(const std::string &login)
{

  //BOOST_LOG_TRIVIAL(debug) << "UserDB: getUserId";
  std::cout << "\n\n\n login " << login << "\n\n\n";

  auto query = "SELECT userId FROM User where login='" + login + "';";
  std::vector<s_record> result;
  int id = exec(
      query.data(), [&result](const s_record &r, void *context) {
        result.emplace_back(r);
        return 0;
      },
      this);

  return std::stoi(result[0][0].col_text);
}

int UserDB::getDeviceId(const User &user)
{
  //BOOST_LOG_TRIVIAL(debug) << "UserDB: getDeviceId";
  return user.deviceId;
}

std::string UserDB::getLogin(const User &user)
{
  //BOOST_LOG_TRIVIAL(debug) << "UserDB: getLogin";
  return user.login;
}

int UserDB::getPassword(const User &user)
{
  //BOOST_LOG_TRIVIAL(debug) << "UserDB: getPassword";
  return selectPassword(user);
}

std::string UserDB::getSynchFolder(const User &user)
{
  //BOOST_LOG_TRIVIAL(debug) << "UserDB: getSynchFolder";
  return user.synchFolder;
}

std::string UserDB::getLastUpdate(User &user)
{
  //BOOST_LOG_TRIVIAL(debug) << "UserDB: getLastUpdate";
  return user.lastUpdate;
}

int UserDB::selectUserId()
{
  //BOOST_LOG_TRIVIAL(debug) << "UserDB: selectUserId";

  const std::string query = "SELECT userId FROM User;";
  std::vector<s_record> result;
  int id = exec(
      query.data(), [&result](const s_record &r, void *context) {
        result.emplace_back(r);
        return 0;
      },
      this);

  for (const auto &rec : result)
  {
    for (const auto &col : rec)
    {
      std::cout << col.col_name << "=" << col.col_text;
    }
    std::cout << '\n';
  }

  std::cout << "Completed successfully and finished working with code ";

  return id;
}

int UserDB::selectDeviceId()
{
  //BOOST_LOG_TRIVIAL(debug) << "UserDB: selectDeviceId";
  std::string query = "SELECT deviceId FROM User;";
  std::vector<s_record> result;
  int device_id = exec(
      query.data(), [&result](const s_record &r, void *context) {
        result.emplace_back(r);
        return 0;
      },
      this);

  for (const auto &rec : result)
  {
    for (const auto &col : rec)
    {
      std::cout << col.col_name << "=" << col.col_text;
    }
    std::cout << '\n';
  }
  std::cout << "Completed successfully and finished working with code ";

  return device_id;
}

int UserDB::selectLogin()
{
  //BOOST_LOG_TRIVIAL(debug) << "UserDB: selectLogin";

  const std::string query = "SELECT login FROM User;";
  std::vector<s_record> result;
  int login = exec(
      query.data(), [&result](const s_record &r, void *context) {
        result.emplace_back(r);
        return 0;
      },
      this);

  for (const auto &rec : result)
  {
    for (const auto &col : rec)
    {
      std::cout << col.col_name << "=" << col.col_text;
    }
    std::cout << '\n';
  }
  std::cout << "Completed successfully and finished working with code ";

  return login;
}

bool UserDB::selectPassword(const User &user)
{
  //BOOST_LOG_TRIVIAL(debug) << "UserDB: selectPassword";

  std::string query = "Select password from User where userId = " + std::to_string(user.userId) + ";";
  std::vector<s_record> result;
  int password = exec(
      query.data(), [&result](const s_record &r, void *context) {
        result.emplace_back(r);
        return 0;
      },
      this);

  for (const auto &rec : result)
  {
    for (const auto &col : rec)
    {
      std::cout << col.col_name << "=" << col.col_text;
    }
    std::cout << '\n';
  }
  std::cout << "Completed successfully and finished working with code ";

  return password;
}

int UserDB::selectFolder()
{
  BOOST_LOG_TRIVIAL(debug) << "UserDB: selectFolder";

  const std::string query = "SELECT synchFolder FROM User;";
  std::vector<s_record> result;
  int folder = exec(
      query.data(), [&result](const s_record &r, void *context) {
        result.emplace_back(r);
        return 0;
      },
      this);

  for (const auto &rec : result)
  {
    for (const auto &col : rec)
    {
      std::cout << col.col_name << "=" << col.col_text;
    }
    std::cout << '\n';
  }
  std::cout << "Completed successfully and finished working with code ";

  return folder;
}

int UserDB::selectLastUpdate()
{
  //BOOST_LOG_TRIVIAL(debug) << "UserDB: selectLastUpdate";
  const std::string query = "SELECT lastUpdate FROM User;";
  std::vector<s_record> result;
  int update = exec(
      query.c_str(), [&result](const s_record &r, void *context) {
        result.emplace_back(r);
        return 0;
      },
      this);

  for (const auto &rec : result)
  {
    for (const auto &col : rec)
    {
      std::cout << col.col_name << "=" << col.col_text;
    }
    std::cout << '\n';
  }
  std::cout << "Completed successfully and finished working with code ";

  return update;
}

bool UserDB::updateSynchFolder(User &user, const std::string &newFolder)
{
  //BOOST_LOG_TRIVIAL(debug) << "UserDB: updateSynchFolder";

  auto query = "Update User set synchFolder = \"" + newFolder + "\" where userId = " + std::to_string(user.userId) + ";";

  user.synchFolder = newFolder;

  //BOOST_LOG_TRIVIAL(debug) << "SynchFolder updated";

  return exec(query.data());
}

bool UserDB::updatePassword(User &user, const std::string &newPassword)
{
  std::string query = "Update User set password = \"" + newPassword + "\" where userId = " + std::to_string(user.userId) + ";";

  user.password = newPassword;

  //BOOST_LOG_TRIVIAL(debug) << "Password updated";

  return exec(query.data());
}

void UserDB::saveLastUpdate(User &user)
{
  //BOOST_LOG_TRIVIAL(debug) << "UserDB: saveLastUpdate";

  auto ttime = time(nullptr);
  auto *local_time = localtime(&ttime);
  std::string lastTMPUpdate = std::to_string(1900 + local_time->tm_year) + "-" + std::to_string(1 + local_time->tm_mon) + "-" + std::to_string(local_time->tm_mday) + " " + std::to_string(local_time->tm_hour) + ":" + std::to_string(local_time->tm_min) + ":" + std::to_string(local_time->tm_sec);
  std::cout << lastTMPUpdate;
  auto query = "Update User set lastUpdate = \"" + boost::lexical_cast<std::string>(lastTMPUpdate) + "\" where userId = " + std::to_string(user.userId) + ";";

  exec(query.data());

  user.lastUpdate = boost::lexical_cast<std::string>(lastTMPUpdate);
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------

FileDB::FileDB(const std::string_view fileNameDB)
{
  if (connect(fileNameDB))
  {
    createTable();
  }
}

bool FileDB::exec(const std::string_view sql,
                  std::function<int(const s_record &r, void *context)> record_callback, void *context)
{
  if (!(_database))
    return false;
  char *err = 0;

  if (record_callback)
  {
    struct s_local_context
    {
      void *context{};
      std::function<int(const s_record &r, void *context)> record_callback{};
    };

    s_local_context lc{context, record_callback};

    if (sqlite3_exec(
            _database.get(), sql.data(), [/*&record_callback*/](void *context, int cols_count, char **texts_array, char **names_array) {
              s_local_context *lc = reinterpret_cast<s_local_context *>(context);
              s_record r;
              r.reserve(cols_count);
              for (int col = 0; col < cols_count; col++)
              {
                s_column c{names_array[col], texts_array[col]};

                r.emplace_back(c);
                //std::cout<<names_array[col]<<"="<<texts_array[col]<<',';
              }
              //std::cout<<'\n';
              return lc->record_callback(r, lc->context);
            },
            &lc, &err))
    {
      fprintf(stderr, "Ошибка SQL: %s\n", err);
      sqlite3_free(err);
      return false;
    }
  }
  else
  {
    if (sqlite3_exec(_database.get(), sql.data(), 0, 0, &err))
    {
      fprintf(stderr, "Ошибка SQL: %s\n", err);
      sqlite3_free(err);
      return false;
    }
  }

  return true;
}

bool FileDB::connect(const std::string_view fileNameDB)
{
  auto pDB = _database.get();
  if (SQLITE_OK != sqlite3_open_v2(fileNameDB.data(), &pDB, SQLITE_OPEN_CREATE | SQLITE_OPEN_READWRITE, nullptr))
  {
    //BOOST_LOG_TRIVIAL(error) << "FileDB can't connect\n";
    return false;
  }

  _database.reset(pDB);
  //BOOST_LOG_TRIVIAL(debug) << "FileDB connect\n";

  return true;
}

void FileDB::disconnect()
{
  //BOOST_LOG_TRIVIAL(debug) << "FileDB close";
  sqlite3_shutdown();
}

void FileDB::createTable()
{
  //BOOST_LOG_TRIVIAL(debug) << "FileDB: createTable";

  exec(R"(
      CREATE TABLE IF NOT EXISTS  "Files" (
      "fileId" INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
      "fileName" TEXT NOT NULL,
      "fileExtention" TEXT NOT NULL,
      "fileSize" INTEGER NOT NULL,
      "filePath" TEXT NOT NULL,
      "chunksCount" INTEGER NOT NULL,
      "version" INTEGER NOT NULL,
      "isDownload" BOOLEAN NOT NULL,
      "updateDate" TEXT NOT NULL,
      "createDate" TEXT NOT NULL);                 
         )",
       0, 0);

  //BOOST_LOG_TRIVIAL(debug) << "FileDB: Table created";
}

void FileDB::addFile(FileMeta &file)
{
  //BOOST_LOG_TRIVIAL(debug) << "FileDB: addFile";

  file.version = 1;
  auto date = getTime_unixtime();
  auto query = "INSERT INTO Files (fileName, fileExtention, fileSize, filePath,"
               " chunksCount, version, isDownload, updateDate, createDate) VALUES ('" +
               file.fileName + "', '" + file.fileExtention + "', " + std::to_string(file.fileSize) + ", '" + file.filePath + "', " +
               std::to_string(file.chunksCount) + ", 1, " + std::to_string(file.isDownload) + ", '" + std::to_string(date) + "', '" + std::to_string(date) + "');";
  file.updateDate = date;
  file.createDate = date;
  exec(query.data());
  file.fileId = selectId();
}

void FileDB::deleteFile(const int &fileId)
{
  //BOOST_LOG_TRIVIAL(debug) << "FileDB: deleteFile";

  auto query = "DELETE FROM Files WHERE fileId = " + std::to_string(fileId) + ";";
  exec(query.data());
}

void FileDB::downloadFile(const int &fileId)
{
  //BOOST_LOG_TRIVIAL(debug) << "FileDB: downloadFile";

  auto query = "UPDATE Files set isDownload = true where fileId = " +
               std::to_string(fileId) + " ;";
  exec(query.data());
}

bool FileDB::isFileExist(const int &fileId)
{
  //BOOST_LOG_TRIVIAL(debug) << "FileDB: isFileExist";

  auto query = "SELECT fileId id FROM Files where id=" + std::to_string(fileId) + ";";
  std::vector<s_record> result;
  int id = exec(
      query.data(), [&result](const s_record &r, void *context) {
        result.emplace_back(r);
        return 0;
      },
      this);

  //BOOST_LOG_TRIVIAL(info) << "FileDB: Check exist file id=" + std::to_string(fileId);
  int count = result.size();

  return count != 0;
}

std::optional<FileMeta> FileDB::getOneFile(const int id)
{
  //BOOST_LOG_TRIVIAL(debug) << "FileDB: getOneFile";

  std::string query = "SELECT * " //fileName, fileExtention, fileSize, filePath, chunksCount, version, isDownload, updateDate, createDate FROM Files";
                      "FROM Files where fileid=" +
                      std::to_string(id);
  std::vector<s_record> result;
  exec(
      query.data(), [&result](const s_record &r, void *context) {
        result.emplace_back(r);
        return 0;
      },
      this);

  if (result.size() == 0)
    return {};

  FileMeta file;
  file.fillMeFromRecord(result[0]);
  return file;
}

std::time_t FileDB::getTime_unixtime()
{
  return std::time(nullptr);
}

int FileDB::selectId()
{
  const std::string query = "SELECT fileId FROM Files ORDER  BY  fileId  DESC Limit 1";
  std::vector<s_record> result;
  int id = exec(
      query.data(), [&result](const s_record &r, void *context) {
        result.emplace_back(r);
        return 0;
      },
      this);

  for (const auto &rec : result)
  {
    for (const auto &col : rec)
    {
      return std::stoi(col.col_text);
    }
    std::cout << '\n';
  }

  return 1;
}

int FileDB::selectFileId()
{
  //BOOST_LOG_TRIVIAL(debug) << "FileDB: selectFileId";

  const std::string query = "SELECT fileId FROM Files;";

  std::vector<s_record> result;
  int id = exec(
      query.data(), [&result](const s_record &r, void *context) {
        result.emplace_back(r);
        return 0;
      },
      this);

  for (const auto &rec : result)
  {
    for (const auto &col : rec)
    {
      std::cout << col.col_name << "=" << col.col_text;
    }
    std::cout << '\n';
  }

  std::cout << "Completed successfully and finished working with code ";

  return id;
}

void FileMeta::fillMeFromRecord(const s_record &r)
{
  *this = {};
  for (auto &col : r)
  {
    if ("fileName" == col.col_name)
    {
      fileName = col.col_text;
      continue;
    }
    if ("fileId" == col.col_name)
    {
      fileId = strtol(col.col_text.c_str(), 0, 10);
      continue;
    }
    if ("fileExtention" == col.col_name)
    {
      fileExtention = col.col_text;
      continue;
    }
    if ("fileSize" == col.col_name)
    {
      fileSize = strtol(col.col_text.c_str(), 0, 10);
      continue;
    }
    if ("filePath" == col.col_name)
    {
      filePath = col.col_text;
      continue;
    }
    if ("chunksCount" == col.col_name)
    {
      chunksCount = strtol(col.col_text.c_str(), 0, 10);
      continue;
    }
    if ("version" == col.col_name)
    {
      version = strtol(col.col_text.c_str(), 0, 10);
      continue;
    }
    if ("isDownload" == col.col_name)
    {
      isDownload = !!strtol(col.col_text.c_str(), 0, 10);
      continue;
    }
    if ("updateDate" == col.col_name)
    {
      updateDate = col.col_text;
      continue;
    }
    if ("createDate" == col.col_name)
    {
      createDate = col.col_text;
      continue;
    }
  }
}

void FileMeta::printContent() const
{
  std::cout << fileName << ",";
  std::cout << fileId << ",";
  std::cout << fileExtention << ",";
  std::cout << createDate << ",";
  std::cout << updateDate << ",";
  std::cout << isDownload << ",";
  std::cout << version << ",";
  std::cout << chunksCount << ",";
  std::cout << filePath << ",";
  std::cout << fileSize << ",";
}

std::vector<FileMeta> FileDB::selectAllFiles()
{
  //BOOST_LOG_TRIVIAL(debug) << "FileDB: selectAllFiles";

  std::vector<FileMeta> list;
  std::string query = "SELECT * FROM Files";
  std::vector<s_record> result;
  int id = exec(
      query.data(), [&result](const s_record &r, void *context) {
        result.emplace_back(r);
        return 0;
      },
      this);

  list.reserve(result.size());
  for (auto &r : result)
  {
    FileMeta file;
    file.fillMeFromRecord(r);
    list.emplace_back(std::move(file));
  }

  return list;
}

void FileDB::updateFile(FileMeta &file)
{
  //BOOST_LOG_TRIVIAL(debug) << "UserDB: updateFile";

  file.version++;
  auto date = getTime_unixtime();
  auto query = "Update Files SET "
               "fileName = '" +
               file.fileName +
               "', fileExtention = '" + file.fileExtention +
               "', fileSize = " + std::to_string(file.fileSize) +
               ",filePath = '" + file.filePath +
               "', chunksCount = " + std::to_string(file.chunksCount) +
               ", version=" + std::to_string(file.version) +
               ", isDownload=" + std::to_string(file.isDownload) +
               ", updateDate = '" + std::to_string(date) +
               "'"
               " WHERE fileId=" +
               std::to_string(file.fileId) + ";";
  file.updateDate = date;

  exec(query.data());
}
