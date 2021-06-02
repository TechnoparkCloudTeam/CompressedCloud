#pragma once

#include <functional>
#include <optional>

#include "UserDB.h"

struct s_column
{
   std::string col_name;
   std::string col_text;
};

struct s_record:public std::vector<s_column>
{
};
struct sqlite3_deleter
{
        void operator()(sqlite3 *sql)
        {
                sqlite3_close_v2(sql);
        }
};
struct IUserDB
{
    
    virtual bool exec(const std::string_view sql,
              std::function<int(const s_record &r, void *context)> record_callback = nullptr //retuen false to continue enumeration
              ,
              void *context = nullptr) = 0;

    virtual bool connect(const std::string_view userNameDB) = 0;
    
    virtual void disconnect() = 0;
    
    virtual void createTable() = 0;

    virtual bool addUser(const User &user) = 0;
    
    virtual void deleteUser(int id) = 0;

    virtual bool isUserExist(const int &userId) = 0;

    virtual int getUserId(const std::string &login) = 0;
    
    virtual int getDeviceId(const User &user) = 0;
    
    virtual std::string getLogin(const User &user) = 0;
    
    virtual int getPassword(const User &user) = 0;
    
    virtual std::string getSynchFolder(const User &user) = 0;
    
    virtual std::string getLastUpdate(User &user) = 0;

    virtual int selectUserId() = 0;
    
    virtual int selectDeviceId() = 0;
    
    virtual int selectLogin() = 0;
    
    virtual bool selectPassword(const User &user) = 0;
    
    virtual int selectFolder() = 0;
    
    virtual int selectLastUpdate() = 0;

    virtual bool updateSynchFolder(User &user, const std::string &newFolder) = 0;
    
    virtual bool updatePassword(User &user, const std::string &newPassword) = 0;

    virtual void saveLastUpdate(User &user) = 0;
};
