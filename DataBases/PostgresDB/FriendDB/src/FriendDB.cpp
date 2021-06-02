#include "FriendDB.h"
//#include <boost/lexical_cast.hpp>
#include <iostream>

void FriendDB::createTable()
{
  const char *sql1 = R"(create table if not exists Friends (
       firstFriend integer,
       secondFriend integer,
       unique (firstfriend, secondfriend)
       ))";
  std::cout << "creating table of Friends\n";
  pqExec(sql1, PostgresExceptions("can't create table of Friends\n"));
}

FriendDB::FriendDB(std::string_view info) : IFriendDB(info) {}

FriendDB &FriendDB::shared(std::string_view info)
{
  static FriendDB shared(info);
  return shared;
}

int FriendDB::getUserIdFromLogin(const std::string &login)
{
  std::string query =
      "SELECT id from Users Where login like '" + login + "';";
  return getUserId(query, PostgresExceptions("invalid to select id"));
}

int FriendDB::getUserId(const std::string &query, PostgresExceptions exceptions)
{
  PGresult *res = PQexec(_conn, query.c_str());
  if (PQresultStatus(res) != PGRES_TUPLES_OK)
  {
    PQexec(_conn, "rollback to savepoint f_savepoint;");
    PQclear(res);
    throw exceptions;
  }
  int id = strtol(PQgetvalue(res, 0, 0), 0, 10);
  PQclear(res);
  return id;
}

bool FriendDB::userExist(const std::string &query)
{
  PGresult *res = PQexec(_conn, query.c_str());
  if (PQresultStatus(res) != PGRES_TUPLES_OK)
  {
    PQexec(_conn, "rollback to savepoint f_savepoint;");
    PQclear(res);
    throw PostgresExceptions("failed to select count of users");
  }
  int id = strtol(PQgetvalue(res, 0, 0), 0, 10);
  PQclear(res);

  return id == 1;
}

void FriendDB::AddFriend(const int &firstFriend, const int &secondFriend)
{
  try
  {
    pqExec("begin;", PostgresExceptions("invalid to start transaction"));         // Начало транзакции
    pqExec("savepoint f_savepoint;", PostgresExceptions("invalid to savepoint")); // Точка сохранения
    auto query = "INSERT INTO friends (firstFriend, secondFriend) VALUES (" + std::to_string(firstFriend) + ", " + std::to_string(secondFriend) + ");";
    pqExec(query, PostgresExceptions("invalid to register friendship"));
    pqExec("commit;", PostgresExceptions("invalid to end transation"));
    std::cout << "Friendship registered" << std::endl;
  }
  catch (PostgresExceptions &exceptions)
  {
    std::cout << exceptions.what() << "\n";
  }
}

bool FriendDB::CheckFriendship(const int &firstFriend, const int &secondFriend)
{
  try
  {
    auto query = "SELECT* FROM friends WHERE (firstFriend = " + std::to_string(firstFriend) + 
    "or firstFriend = " + std::to_string(secondFriend) + ") AND (secondFriend = " +
     std::to_string(secondFriend) + " or secondFriend = " + std::to_string(firstFriend) + ");"; 
    PGresult *res = PQexec(_conn, query.c_str());
    if (PQresultStatus(res) != PGRES_TUPLES_OK)
    {
      PQexec(_conn, "rollback to savepoint f_savepoint;");
      PQclear(res);
      throw PostgresExceptions("failed to select count of users");
    } 
    bool friendShip = 0;
    std::cout << "\nrecords count: " << PQntuples(res);
    if (PQntuples(res) == 2) {
      friendShip = 1;
    }
    PQclear(res);
    return friendShip;
  }
  catch (PostgresExceptions &exceptions)
  {
    std::cout << exceptions.what() << "\n";
    return 0;
  }
}