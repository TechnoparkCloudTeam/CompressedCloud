#pragma once

#include <vector>
#include <string>

#include "PostgresExceptions.h"
#include "UserInfo.h"
#include "UserIds.h"
#include "IUserDB.h"

class UsersDB : public IUserDB
{
public:
  ~UsersDB() override = default;
  
  static UsersDB &shared(std::string_view info);
  
  void createTable() override;
  
  bool Login(const UserInfo &userInfo) override;
  
  UserInfo Registration(const UserInfo &userInfo) override;
  
  int getUserIdFromLogin(const std::string &login) override;

private:
  explicit UsersDB(std::string_view info);
  
  UsersDB(const UsersDB &users_db);
  
  UsersDB &operator=(const UsersDB &users_db);
  
  bool isPasswordCorrect(const std::string &query, const UserInfo &userInfo, PostgresExceptions exceptions);
  
  bool userExist(const std::string &query);
  
  int getUserId(const std::string &query, PostgresExceptions exceptions);
};
