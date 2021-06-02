#pragma once

#include <filesystem>

#include "LocalDB.h"

struct IIndexer
{
    virtual void createFile(const std::filesystem::path& path) = 0;
    virtual void modifyFile(const std::filesystem::path& path, size_t chunksCnt) = 0;
    virtual void deleteFile(const std::filesystem::path& path) = 0;
    virtual void AddUser(const std::string& UserLogin, const std::string& UserPassword) = 0;
    virtual FileMeta GetFileInfo(const std::filesystem::path& path) = 0;
};
