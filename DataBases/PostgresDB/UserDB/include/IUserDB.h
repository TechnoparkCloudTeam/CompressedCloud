#pragma once

#include "PostgreSQLDB.h"

struct IUserDB : public PostgresSQLDB
{
    explicit IUserDB(std::string_view info) : PostgresSQLDB(info){};
    
    virtual void createTable() = 0;
    
    virtual bool Login(const UserInfo &userInfo) = 0;
    
    virtual UserInfo Registration(const UserInfo &userInfo) = 0;
    
    virtual int getUserIdFromLogin(const std::string &login) = 0;
};