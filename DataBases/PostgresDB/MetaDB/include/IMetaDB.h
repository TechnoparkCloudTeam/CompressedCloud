#pragma once

#include <vector>
#include "PostgreSQLDB.h"
#include "FileInfo.h"
#include "UserDate.h"
struct IMetaDataDB : public PostgresSQLDB
{
    explicit IMetaDataDB(std::string_view info) : PostgresSQLDB(info){};

    virtual void createTable() = 0;
    
    virtual void InsertFile(const FileMeta &fileMeta) = 0;
    
    virtual std::vector<FileInfo> GetUserFilesByTime(const UserDate &userDate) = 0;
    
    virtual bool isFileExist(std::string login) = 0;
    
    virtual void deleteFile(std::string login, std::string fileName) = 0;
    
    virtual std::string GetFile(std::string login) = 0;
};
