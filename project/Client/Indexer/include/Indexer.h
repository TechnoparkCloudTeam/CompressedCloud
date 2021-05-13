#pragma once
#include <vector>
#include <filesystem>
#include <memory>
#include "../../../DataBases/LocalDB/include/LocalDB.h"


class I_Indexer {
public:
    virtual void createFile(const std::filesystem::path& path, size_t chunksCnt) = 0;
    virtual void modifyFile(const std::filesystem::path& path, size_t chunksCnt) = 0;
    virtual void renameFile(const std::filesystem::path& oldPath,
        const std::filesystem::path& newPath) = 0;
    virtual void deleteFile(const std::filesystem::path& path) = 0;
    virtual void getFileInfo(const std::filesystem::path& path) = 0;
    
};

class Indexer : public I_Indexer {
public:
    Indexer (std::shared_ptr<UserDB> localDB);
    void createFile(const std::filesystem::path& path, size_t chunksCnt) override;
    void modifyFile(const std::filesystem::path& path, size_t chunksCnt) override;
    void renameFile(const std::filesystem::path& oldPath,
        const std::filesystem::path& newPath) override;
    void deleteFile(const std::filesystem::path& path) override;
    void getFileInfo(const std::filesystem::path& path) override;
    void AddUser(UserDB& DB);
    Indexer();
private:
    std::shared_ptr<UserDB> LocalDataBase;

};

