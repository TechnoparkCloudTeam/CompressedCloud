#pragma once

#include <vector>
#include <filesystem>
#include <memory>
#include <iostream>

#include "LocalDB.h"
#include "IIndexer.h"

std::string GetCurrentTime();

std::string GetDirStartingFromBuild(const std::filesystem::path &path);

class Indexer : public IIndexer
{
public:
    Indexer(std::shared_ptr<IFileDB> FileDataBase, std::shared_ptr<IUserDB> UserDataBase);
    void createFile(const std::filesystem::path &path) override;
    void modifyFile(const std::filesystem::path &path, size_t chunksCnt) override;
    void deleteFile(const std::filesystem::path &path) override;
    void AddUser(const std::string &UserLogin, const std::string &UserPassword) override;
    FileMeta GetFileInfo(const std::filesystem::path &path) override;

private:
    std::shared_ptr<IFileDB> LocalFileDataBase;
    std::shared_ptr<IUserDB> LocalUserDataBase;
};
