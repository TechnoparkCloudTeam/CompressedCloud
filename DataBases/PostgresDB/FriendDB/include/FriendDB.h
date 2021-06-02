#pragma once

#include <vector>
#include <string>
#include "PostgreSQLDB.h"
#include "PostgresExceptions.h"
#include "UserInfo.h"
#include "UserIds.h"
#include "IFriendDB.h"

class FriendDB : public IFriendDB
{
public:
  ~FriendDB() override = default;
  
  explicit FriendDB(std::string_view info);
  
  FriendDB(const FriendDB &users_db);
  
  FriendDB &operator=(const FriendDB &users_db);
  
  static FriendDB &shared(std::string_view info);
  
  void createTable() override;
  
  int getUserIdFromLogin(const std::string &login) override;
  
  void AddFriend(const int &firstFriend, const int &secondFriend) override;
  
  bool CheckFriendship(const int &firstFriend, const int &secondFriend) override;

private:
  bool userExist(const std::string &query);
  
  int getUserId(const std::string &query, PostgresExceptions exceptions);
};
