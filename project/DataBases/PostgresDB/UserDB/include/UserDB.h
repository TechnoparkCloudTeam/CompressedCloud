#pragma once

#include <vector>
#include <string>
#include "PostgreSQLDB.h"
#include "PostgresExceptions.h"
#include "UserInfo.h"
#include "UserIds.h"

class UsersDB : public PostgresSQLDB {
 public:
  ~UsersDB() override = default;
  static UsersDB &shared(std::string_view info);
  UserIds Login(const UserInfo &userInfo);
  UserIds Registration(const UserInfo &userInfo);

 //private:
  explicit UsersDB(std::string_view info);
  UsersDB(const UsersDB &users_db);
  UsersDB &operator=(const UsersDB &users_db);
  bool isPasswordCorrect(const std::string &query, const UserInfo &userInfo, PostgresExceptions exceptions);
  bool userExist(const std::string &query);
  int getUserId(const std::string &query, PostgresExceptions exceptions);
};

