#include "MetaDB.h"
#include <iomanip>
#include <boost/lexical_cast.hpp>
#include <iostream>
//#include <boost/log/trivial.hpp>
MetaDataDB::MetaDataDB(std::string_view info)
    : PostgresSQLDB(info) {
}

MetaDataDB &MetaDataDB::shared(std::string_view info) {
  static MetaDataDB shared(info);
  return shared;
}

void MetaDataDB::InsertFile(const FileInfo &fileMeta) {
 // BOOST_LOG_TRIVIAL(debug) << "PostgresSQLDB: InsertFile";
  // auto updateDate = fileMeta.file.updateDate;
  // std::string dateUpdate = getTime(updateDate);
  // auto createDate = fileMeta.file.createDate;
  // std::string dateCreateDate = getTime(createDate);

  try {
    pqExec("begin;", PostgresExceptions("invalid to start transaction"));  // Начало транзакции
    std::cout << "PostgresSQLDB: Begin transaction\n";
    pqExec("savepoint f_savepoint;", PostgresExceptions("invalid to insert\n"));  // Точка сохранения

    /* std::cout << "PostgresSQLDB: Update file\n";
    std::string query = "Update Files set isCurrent = 0 where fileId = "
        + std::to_string(fileMeta.file.fileId)
        + " and userId = "
        + std::to_string(fileMeta.userId) + ";\n";
    pqExec(query, PostgresExceptions("invalid to insert"));  // Снятие старой версии
*/
    std::string query =
        "INSERT INTO Files (fileId, userId, fileName, fileExtention, filePath ,fileSize, chunksCount, version, isCurrent, isDeleted, updateDate, createDate) VALUES ("
            + std::to_string(fileMeta.file.fileId)
            + ", " + std::to_string(fileMeta.userId)
            + ", '" + fileMeta.file.fileName
            + "', '" + fileMeta.file.fileExtension
            + "', '" + fileMeta.file.filePath
            + "', " + std::to_string(fileMeta.file.fileSize)
            + ", " + std::to_string(fileMeta.file.chunksCount)
            + ", " + std::to_string(fileMeta.file.version)
            + ", '" + std::to_string(fileMeta.file.isCurrent)
            + "', '" + std::to_string(fileMeta.file.isDeleted)
            + "', " + "'" + fileMeta.file.updateDate + "'," + "'" + fileMeta.file.createDate + "');";
    std::cout << "PostgresSQLDB: Insert file\n";

    std::cout << "\n\n"<<query<<"\n\n";
    pqExec(query, PostgresExceptions("invalid to insert data to db\n"));  // Добавление нового файла
#if 0

// ???
    
    for (const auto &chunk : fileMeta.chunkMeta) {
      query = "INSERT INTO Chunks (id_chunk_for_user, id_user) VALUES ("
          + std::to_string(chunk.chunkId) + ","
          + std::to_string(fileMeta.userId) + ");";
      pqExec(query, PostgresExceptions("invalid to insert data to db"));  // Добавление нового чанка
    }

    query = "SELECT id FROM Files Where id_file_for_user = "
        + std::to_string(fileMeta.file.fileId)
        + "and id_user = "
        + std::to_string(fileMeta.userId)
        + " ORDER  BY  id  DESC Limit 1;";

    int id = getLastIdOfFileUser(query, PostgresExceptions("invalid to select id"));
    for (const auto &version : fileMeta.fileChunksMeta) {
      query = "INSERT INTO Version (id_file , id_chunk, id_order) VALUES ("
          + std::to_string(id) + ", "
          + std::to_string(version.chunkId) + ", "
          + std::to_string(version.chunkOrder) + ");";
     std::cout << "PostgresSQLDB: Insert chunks";
      pqExec(query, PostgresExceptions("invalid to insert data to db"));  // Добавление новой версии
    }
#endif
  std::cout << "PostgresSQLDB: End transaction";
    pqExec("commit;", PostgresExceptions("invalid to end transation"));  // Завершение транзакции
  }
  catch (PostgresExceptions &exceptions) {
    throw PostgresExceptions(exceptions.what());
  }
}

int MetaDataDB::getLastIdOfFileUser(const std::string &query, PostgresExceptions exceptions) {
std::cout<< "PostgresSQLDB: getLastIdOfFileUser";
  PGresult *res = PQexec(_conn, query.c_str());
  if (PQresultStatus(res) != PGRES_TUPLES_OK) {
    PQexec(_conn, "rollback to savepoint f_savepoint;");
    PQclear(res);
    throw exceptions;
  }
  int id = boost::lexical_cast<int>(PQgetvalue(res, 0, 0));
  PQclear(res);
  return id;
}

std::vector<FileInfo> MetaDataDB::GetUserFilesByTime(const UserDate &userDate) {
  std::vector<FileInfo> filesInfo;
std::cout << "PostgresSQLDB: GetUserFilesByTime";
  std::string query = "Select * from Files Where userId = " + std::to_string(userDate.userId)
      + " and updateDate > '" + userDate.date + "' ORDER BY id;";
  PGresult *res = PQexec(_conn, query.c_str());
  if (PQresultStatus(res) != PGRES_TUPLES_OK) {
    printf("No data retrieved\n");
  }
  int rows = PQntuples(res);
  for (int i = 0; i < rows; i++) {
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
    if (PQresultStatus(resChunks) != PGRES_TUPLES_OK) {
std::cout << "PostgresSQLDB: Faild to get data";
      throw PostgresExceptions("PostgresSQLDB: PGRES_TUPLES_OK");
    }
    int rowsChunks = PQntuples(resChunks);

    for (int j = 0; j < rowsChunks; j++) {
      FileChunksMeta chunkMeta{
          .chunkId = boost::lexical_cast<int>(PQgetvalue(resChunks, j, 2)),
          .chunkOrder = boost::lexical_cast<int>(PQgetvalue(resChunks, j, 3))};
      fileInfo.fileChunksMeta.push_back(chunkMeta);
    }

    filesInfo.push_back(fileInfo);
  }
std::cout << "PostgresSQLDB: count files = " << filesInfo.size();

  return filesInfo;
}

std::string MetaDataDB::getTime(std::string &time) {
  time.erase(std::find(time.begin(), time.end(), '.'), time.end());

  std::time_t ttime;
  try {
    ttime = boost::lexical_cast<int>(time);
  } catch (std::exception &exception) {
    struct std::tm tm{};
    std::istringstream ss(time);
    ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
    ttime = mktime(&tm);
  }

  auto *local_time = localtime(&ttime);
  std::string date = std::to_string(1900 + local_time->tm_year) + "-" + std::to_string(1 + local_time->tm_mon) + "-"
      + std::to_string(local_time->tm_mday) + " " + std::to_string(local_time->tm_hour) + ":"
      + std::to_string(local_time->tm_min) + ":" + std::to_string(local_time->tm_sec);

  return date;
}

