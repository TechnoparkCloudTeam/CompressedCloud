#pragma once
#include <vector>
#include <filesystem>
#include <memory>
#include "ChunkDB.h"
#include "DeviceDB.h"
#include "FileDB.h"

#include "UserDB.h"

class I_Indexer {
public:
    virtual FileMeta createFile(const std::filesystem::path& path, size_t chunksCnt) = 0;
    virtual FileMeta modifyFile(const std::filesystem::path& path, size_t chunksCnt) = 0;
    virtual FileMeta renameFile(const std::filesystem::path& oldPath,
        const std::filesystem::path& newPath) = 0;
    virtual FileMeta deleteFile(const std::filesystem::path& path) = 0;
    virtual FileMeta getFileInfo(const std::filesystem::path& path) = 0;
};

class Indexer : public I_Indexer {
public:
    Indexer (LocalDB& localDB);
    FileMeta createFile(const std::filesystem::path& path, size_t chunksCnt) override;
    FileMeta modifyFile(const std::filesystem::path& path, size_t chunksCnt) override;
    FileMeta renameFile(const std::filesystem::path& oldPath,
        const std::filesystem::path& newPath) override;
    FileMeta deleteFile(const std::filesystem::path& path) override;
    FileMeta getFileInfo(const std::filesystem::path& path) override;
private:
    std::shared_ptr<LocalDB> localDB;
    std::shared_ptr<DeviceDB> deviceDB;
    std::shared_ptr<ChunkDB> chunkDB;
    std::shared_ptr<UserDB> userDB;
    std::shared_ptr<FileDB> fileDB;
};

