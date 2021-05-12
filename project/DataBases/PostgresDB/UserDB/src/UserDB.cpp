#include "UserDB.h"
#include <boost/lexical_cast.hpp>

UserIds UsersDB::Login(const UserInfo &userInfo) {
  try {
    pqExec("begin;", PostgresExceptions("invalid to start transaction"));  // Начало транзакции
    pqExec("savepoint f_savepoint;", PostgresExceptions("invalid to insert"));  // Точка сохранения
    std::string query = "SELECT count(*) from Users Where login like '" + userInfo.login + "' ;";

	if (!userExist(query)) {
	  throw PostgresExceptions("No one such user");
	}

    query = "SELECT password from Users Where login like '" + userInfo.login + "';";
	if (!isPasswordCorrect(query, userInfo)) {
	  throw PostgresExceptions("incorrent password");
	}
	query =
		"SELECT id from Users Where login like '" + userInfo.login + "' and password like '" + userInfo.password
			+ "';";
	UserIds usr{.id = getUserId(query, PostgresExceptions("invalid to select id"))};
    pqExec("commit;", PostgresExceptions("invalid to end transation"));
    return usr;
  } catch (PostgresExceptions &exceptions) {
    throw PostgresExceptions(exceptions.what());
  }
}
UserIds UsersDB::Registration(const UserInfo &userInfo) {
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
  /*
    UserIds usr{.id = getUserId(query, PostgresExceptions("invalid to select id"))};
    pqExec("commit;", PostgresExceptions("invalid to end transation"));
    return usr;*/
  } catch (PostgresExceptions &exceptions) {
    throw PostgresExceptions(exceptions.what());
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
  int id = boost::lexical_cast<int>(PQgetvalue(res, 0, 0));
  PQclear(res);
  return id;
}

bool UsersDB::isPasswordCorrect(const std::string &query, const UserInfo &userInfo) {
  PGresult *res = PQexec(_conn, query.c_str());
  if (PQresultStatus(res) != PGRES_TUPLES_OK) {
	PQexec(_conn, "rollback to savepoint f_savepoint;");
	PQclear(res);
	throw PostgresExceptions("faild to select count of users");
  }
  auto password = boost::lexical_cast<std::string>(PQgetvalue(res, 0, 0));
  PQclear(res);

  return password==userInfo.password;
}

bool UsersDB::userExist(const std::string &query) {
  PGresult *res = PQexec(_conn, query.c_str());
  if (PQresultStatus(res) != PGRES_TUPLES_OK) {
    PQexec(_conn, "rollback to savepoint f_savepoint;");
    PQclear(res);
    throw PostgresExceptions("faild to select count of users");
  }
  int id = boost::lexical_cast<int>(PQgetvalue(res, 0, 0));
  PQclear(res);

  return id == 1;
}

