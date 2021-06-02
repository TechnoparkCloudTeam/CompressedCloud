#include "MetaDB.h"
#include <iomanip>
#include <boost/lexical_cast.hpp>
#include <iostream>
//#include <boost/log/trivial.hpp>

void MetaDataDB::createTable()
{
  const char *sql = R"(create table if not exists Files (
       fileId serial primary key,
       userId integer,
       version integer,
       fileName text,
       fileExtention text,
       filePath text,
       fileSize integer,
       chunksCount integer,
       isDownload boolean,
       isDeleted boolean,
       isCurrent boolean,
       updateDate timestamp,
       createDate timestamp,
       foreign key (userId) references users(id)
))";
  std::cout << "creating table of Files\n";
  pqExec(sql, PostgresExceptions("can't create table of Files\n"));
}

MetaDataDB::MetaDataDB(std::string_view info)
    : IMetaDataDB(info)
{
}

MetaDataDB &MetaDataDB::shared(std::string_view info)
{
  static MetaDataDB shared(info);
  return shared;
}

void MetaDataDB::InsertFile(const FileMeta &fileMeta)
{

  try
  {
    pqExec("begin;", PostgresExceptions("invalid to start transaction")); // Начало транзакции
    std::cout << "PostgresSQLDB: Begin transaction\n";
    pqExec("savepoint f_savepoint;", PostgresExceptions("invalid to insert\n")); // Точка сохранения
    std::string query =
        "INSERT INTO Files (userId, fileName, fileExtention, filePath ,fileSize, chunksCount, version, isCurrent, isDeleted, updateDate, createDate) VALUES ("
        /* + ", "*/
        + std::to_string(fileMeta.userId) + ", '" + fileMeta.fileName + "', '" + fileMeta.fileExtension + "', '" + fileMeta.filePath + "', " + std::to_string(fileMeta.fileSize) + ", " + std::to_string(fileMeta.chunksCount) + ", " + std::to_string(fileMeta.version) + ", '" + std::to_string(fileMeta.isCurrent) + "', '" + std::to_string(fileMeta.isDeleted) + "', " + "'" + fileMeta.updateDate + "'," + "'" + fileMeta.createDate + "');";
    std::cout << "PostgresSQLDB: Insert file\n";

    std::cout << "\n\n"
              << query << "\n\n";
    pqExec(query, PostgresExceptions("invalid to insert data to db\n")); // Добавление нового файла
    std::cout << "PostgresSQLDB: End transaction";
    pqExec("commit;", PostgresExceptions("invalid to end transation")); // Завершение транзакции
  }
  catch (PostgresExceptions &exceptions)
  {
    throw PostgresExceptions(exceptions.what());
  }
}

int MetaDataDB::getLastIdOfFileUser(const std::string &query, PostgresExceptions exceptions)
{
  std::cout << "PostgresSQLDB: getLastIdOfFileUser";
  PGresult *res = PQexec(_conn, query.c_str());
  if (PQresultStatus(res) != PGRES_TUPLES_OK)
  {
    PQexec(_conn, "rollback to savepoint f_savepoint;");
    PQclear(res);
    throw exceptions;
  }
  int id = boost::lexical_cast<int>(PQgetvalue(res, 0, 0));
  PQclear(res);
  return id;
}

std::vector<FileInfo> MetaDataDB::GetUserFilesByTime(const UserDate &userDate)
{
  std::vector<FileInfo> filesInfo;
  std::cout << "PostgresSQLDB: GetUserFilesByTime";
  std::string query = "Select * from Files Where userId = " + std::to_string(userDate.userId) + " and updateDate > '" + userDate.date + "' ORDER BY id;";
  PGresult *res = PQexec(_conn, query.c_str());
  if (PQresultStatus(res) != PGRES_TUPLES_OK)
  {
    printf("No data retrieved\n");
  }
  int rows = PQntuples(res);
  for (int i = 0; i < rows; i++)
  {
    FileInfo fileInfo;
    fileInfo.userId = userDate.userId;
    fileInfo.file.fileId = boost::lexical_cast<int>(PQgetvalue(res, i, 1));
    fileInfo.file.fileName = boost::lexical_cast<std::string>(PQgetvalue(res, i, 3));
    fileInfo.file.fileExtension = boost::lexical_cast<std::string>(PQgetvalue(res, i, 4));
    fileInfo.file.filePath = boost::lexical_cast<std::string>(PQgetvalue(res, i, 5));
    fileInfo.file.fileSize = boost::lexical_cast<int>(PQgetvalue(res, i, 6));
    fileInfo.file.chunksCount = boost::lexical_cast<int>(PQgetvalue(res, i, 7));
    fileInfo.file.version = boost::lexical_cast<int>(PQgetvalue(res, i, 8));
    fileInfo.file.isCurrent = boost::lexical_cast<int>(PQgetvalue(res, i, 9));
    fileInfo.file.isDeleted = boost::lexical_cast<int>(PQgetvalue(res, i, 10));
    fileInfo.file.updateDate = boost::lexical_cast<std::string>(PQgetvalue(res, i, 11));
    fileInfo.file.createDate = boost::lexical_cast<std::string>(PQgetvalue(res, i, 12));

    auto id = boost::lexical_cast<int>(PQgetvalue(res, i, 0));
    query = "Select * from version where fileId = " + std::to_string(id) + ";";
    PGresult *resChunks = PQexec(_conn, query.c_str());
    if (PQresultStatus(resChunks) != PGRES_TUPLES_OK)
    {
      std::cout << "PostgresSQLDB: Faild to get data";
      throw PostgresExceptions("PostgresSQLDB: PGRES_TUPLES_OK");
    }
    int rowsChunks = PQntuples(resChunks);

    for (int j = 0; j < rowsChunks; j++)
    {
      FileChunksMeta chunkMeta{
          .chunkId = boost::lexical_cast<int>(PQgetvalue(resChunks, j, 2)),
          .chunkOrder = boost::lexical_cast<int>(PQgetvalue(resChunks, j, 3))};
      fileInfo.fileChunksMeta.push_back(chunkMeta);
    }

    filesInfo.push_back(fileInfo);
  }
  std::cout << "PostgresSQLDB: count files = " << filesInfo.size() << std::endl;

  return filesInfo;
}

std::string MetaDataDB::getTime(std::string &time)
{
  time.erase(std::find(time.begin(), time.end(), '.'), time.end());

  std::time_t ttime;
  try
  {
    ttime = boost::lexical_cast<int>(time);
  }
  catch (std::exception &exception)
  {
    struct std::tm tm
    {
    };
    std::istringstream ss(time);
    ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
    ttime = mktime(&tm);
  }

  auto *local_time = localtime(&ttime);
  std::string date = std::to_string(1900 + local_time->tm_year) + "-" + std::to_string(1 + local_time->tm_mon) + "-" + std::to_string(local_time->tm_mday) + " " + std::to_string(local_time->tm_hour) + ":" + std::to_string(local_time->tm_min) + ":" + std::to_string(local_time->tm_sec);

  return date;
}

bool MetaDataDB::isFileExist(std::string login)
{
  std::string query = "SELECT id from Users Where login like '" + login + "' ;";
  PGresult *res1 = PQexec(_conn, query.c_str());
  int id = strtol(PQgetvalue(res1, 0, 0), 0, 10);
  query = "SELECT * from Files Where userId =" + std::to_string(id) + " ;";
  PGresult *res = PQexec(_conn, query.c_str());
  if (PQresultStatus(res) != PGRES_TUPLES_OK)
  {
    PQexec(_conn, "rollback to savepoint f_savepoint;");
    PQclear(res);
    throw PostgresExceptions("faild to select file");
  }
  int isFileExist = strtol(PQgetvalue(res, 0, 0), 0, 10);
  if (isFileExist != 0)
  {
    return true;
  }
  return false;
}

void MetaDataDB::deleteFile(std::string login, std::string fileName)
{
  auto query = "SELECT id from Users Where login like '" + login + "' ;";
  PGresult *res1 = PQexec(_conn, query.c_str());
  int id = strtol(PQgetvalue(res1, 0, 0), 0, 10);
  query = "DELETE from Files Where userId =" + std::to_string(id) + " and fileName like '" + fileName + "' ;";
  PGresult *res = PQexec(_conn, query.c_str());
  if (PQresultStatus(res1) != PGRES_TUPLES_OK)
  {
    PQexec(_conn, "rollback to savepoint f_savepoint;");
    PQclear(res);
    throw PostgresExceptions("faild to delete file");
  }
}

std::string MetaDataDB::GetFile(std::string login)
{
  std::string fileName = "";
  std::string result = "";
  std::string query = "SELECT id from Users Where login like '" + login + "' ;";
  PGresult *res1 = PQexec(_conn, query.c_str());
  int id = strtol(PQgetvalue(res1, 0, 0), 0, 10);
  query = "select fileName from Files Where userId =" + std::to_string(id) + " ;";
  PGresult *res = PQexec(_conn, query.c_str());
  if (PQresultStatus(res1) != PGRES_TUPLES_OK)
  {
    PQexec(_conn, "rollback to savepoint f_savepoint;");
    PQclear(res);
    throw PostgresExceptions("faild to select file");
  }
  int rows = PQntuples(res);
  for (int i = 0; i < rows; i++)
  {
    fileName = boost::lexical_cast<std::string>(PQgetvalue(res, i, 0));
    result = result + " " + fileName;
  }
  return result;
}
