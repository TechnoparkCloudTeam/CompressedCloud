#include "UserDB.h"
//#include <boost/lexical_cast.hpp>
#include <iostream>


void UsersDB::createTable() {
   const char* sql1=R"(create table if not exists Users (
       login text,
       password text,
       id serial primary key
       ))";
    std::cout << "creating table of Users\n";
    pqExec(sql1, PostgresExceptions("can't create table of Users\n"));
}

bool UsersDB::Login(const UserInfo &userInfo) {
  try {
    pqExec("begin;", PostgresExceptions("invalid to start transaction"));  // Начало транзакции
    pqExec("savepoint f_savepoint;", PostgresExceptions("invalid to insert"));  // Точка сохранения
    std::string query = "SELECT count(*) from Users Where login like '" + userInfo.login + "' ;";

	if (!userExist(query)) {
	  return false;
	}

    query = "SELECT password from Users Where login like '" + userInfo.login + "';";
	if (!isPasswordCorrect(query, userInfo, PostgresExceptions("wrong password of user\n"))) {
	  throw PostgresExceptions("incorrect password");
	}
	query =
		"SELECT id from Users Where login like '" + userInfo.login + "' and password like '" + userInfo.password
			+ "';";
	UserInfo usr{.id = getUserId(query, PostgresExceptions("invalid to select id"))};
    pqExec("commit;", PostgresExceptions("invalid to end transation"));
    std::cout << "User logged in" << std::endl;
    return true;
  } catch (PostgresExceptions &exceptions) {
    throw PostgresExceptions(exceptions.what());
  }
}
UserInfo UsersDB::Registration(const UserInfo &userInfo) {
  try {
    pqExec("begin;", PostgresExceptions("invalid to start transaction"));  // Начало транзакции
    pqExec("savepoint f_savepoint;", PostgresExceptions("invalid to savepoint"));  // Точка сохранения

     std::string query = "SELECT count(*) from Users Where login like '" + userInfo.login + "' ;";
    if (userExist(query)) {
      throw PostgresExceptions("User already exist");
    }

    query = "INSERT INTO Users (login, password) VALUES ('" + userInfo.login + "', '" + userInfo.password + "');";
    pqExec(query, PostgresExceptions("invalid to register user"));
	query =
		"SELECT id from Users Where login like '" + userInfo.login + "' and password like '" + userInfo.password
			+ "';";
    UserInfo usr{.id = getUserId(query, PostgresExceptions("invalid to select id"))};
    pqExec("commit;", PostgresExceptions("invalid to end transation"));
    std::cout << "User registered" << std::endl;
    return usr;
  } catch (PostgresExceptions &exceptions) {

    std::cout << exceptions.what() << "\n";
    return UserInfo{};
  }
}
UsersDB::UsersDB(std::string_view info) : PostgresSQLDB(info) {}

UsersDB &UsersDB::shared(std::string_view info) {
  static UsersDB shared(info);
  return shared;
}

int UsersDB::getUserId(const std::string &query, PostgresExceptions exceptions) {
  PGresult *res = PQexec(_conn, query.c_str());
  if (PQresultStatus(res) != PGRES_TUPLES_OK) {
    PQexec(_conn, "rollback to savepoint f_savepoint;");
    PQclear(res);
    throw exceptions;
  }
  int id = strtol(PQgetvalue(res, 0, 0),0,10);
  PQclear(res);
  return id;
}

bool UsersDB::isPasswordCorrect(const std::string &query, const UserInfo &userInfo, PostgresExceptions exceptions) {
  PGresult *res = PQexec(_conn, query.c_str());
  if (PQresultStatus(res) != PGRES_TUPLES_OK) {
	PQexec(_conn, "rollback to savepoint f_savepoint;");
	PQclear(res);
	throw PostgresExceptions("faild to select count of users");
  }
  auto compare_result = strtol(PQgetvalue(res, 0, 0),0,10);
  PQclear(res);

  return !!compare_result;
}

bool UsersDB::userExist(const std::string &query) {
  PGresult *res = PQexec(_conn, query.c_str());
  if (PQresultStatus(res) != PGRES_TUPLES_OK) {
    PQexec(_conn, "rollback to savepoint f_savepoint;");
    PQclear(res);
    throw PostgresExceptions("faild to select count of users");
  }
  int id = strtol(PQgetvalue(res, 0, 0),0,10);
  PQclear(res);

  return id == 1;
}

