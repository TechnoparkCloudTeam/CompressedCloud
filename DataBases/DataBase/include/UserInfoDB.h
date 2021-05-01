#pragma once
#ifndef POSTGRESDB_H
#define POSTGRESDB_H

#include <string>
#include "IUserInfoDB.h"
#include "PostgresDB.h"

class UserInfoDB : public IUserInfoDB, public PostgresDB {
public:
        int login(const UserInfo &user) override;
        int registration(const UserInfo &user) override;
private:
        bool userExists(const std::string &query, const UserInfo&user);
        bool checkPassword(const std::string &query);
        int getUserId(const std::string &query);
};


#endif

