#pragma once

#include <vector>
#include <string>
#include "PostgreSQLDB.h"
#include "PostgresExceptions.h"
#include "UserInfo.h"
#include "UserIds.h"

class FriendDB : public PostgresSQLDB {
 public:
  ~FriendDB() override = default;
  static FriendDB &shared(std::string_view info);
  void createTable();
  int getUserIdFromLogin(const std::string& login);
  void AddFriend(const int& firstFriend, const int& secondFriend);
  bool CheckFriendship(const int& firstFriend, const int& secondFriend);
 //private:
  explicit FriendDB(std::string_view info);
  FriendDB(const FriendDB &users_db);
  FriendDB &operator=(const FriendDB &users_db);
  bool userExist(const std::string &query);
  int getUserId(const std::string &query, PostgresExceptions exceptions);
};

