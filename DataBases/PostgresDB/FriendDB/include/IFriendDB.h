#pragma once

#include <string>
#include "PostgreSQLDB.h"

struct IFriendDB : public PostgresSQLDB
{
    explicit IFriendDB(std::string_view info) : PostgresSQLDB(info){};
    
    virtual ~IFriendDB() override = default;
    
    virtual void createTable() = 0;
    
    virtual int getUserIdFromLogin(const std::string &login) = 0;
    
    virtual void AddFriend(const int &firstFriend, const int &secondFriend) = 0;
    
    virtual bool CheckFriendship(const int &firstFriend, const int &secondFriend) = 0;
};
