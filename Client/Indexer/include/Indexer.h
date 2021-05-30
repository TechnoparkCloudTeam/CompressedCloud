#pragma once
#include <vector>
#include <filesystem>
#include <memory>
#include "../../../DataBases/LocalDB/include/LocalDB.h"

std::string GetCurrentTime();

std::string GetDirStartingFromBuild(const std::filesystem::path& path);

class I_Indexer {
public:
    virtual void createFile(const std::filesystem::path& path) = 0;
    virtual void modifyFile(const std::filesystem::path& path, size_t chunksCnt) = 0;
    virtual void deleteFile(const std::filesystem::path& path) = 0;
    
};

class Indexer : public I_Indexer {
public:
    Indexer (std::shared_ptr<FileDB> FileDataBase, std::shared_ptr<UserDB> UserDataBase);
    void createFile(const std::filesystem::path& path) override;
    void modifyFile(const std::filesystem::path& path, size_t chunksCnt) override;
    void deleteFile(const std::filesystem::path& path) override;
    void AddUser(const std::string& UserLogin, const std::string& UserPassword);
    FileMeta GetFileInfo(const std::filesystem::path& path);
private:
    std::shared_ptr<FileDB> LocalFileDataBase;
    std::shared_ptr<UserDB> LocalUserDataBase;
};

