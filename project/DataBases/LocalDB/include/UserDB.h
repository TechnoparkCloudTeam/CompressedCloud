#pragma once
#include <memory>
#include <string>
#include "LocalDB.h"

struct User {
        int userId;
        std::string login;
        std::string password;
        int deviceId;
        std::string deviceName;
        std::string synchFolder;
        std::string lastUpdate;
};

class UserDB {
public:
        int selectUserId();
        void deleteUser();
        int getUserId() const;
        void addUser(const User &user);
private:
        std::shared_ptr<LocalDB> localDB;
        User user;
};
