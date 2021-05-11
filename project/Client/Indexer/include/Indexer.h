#pragma once
#include <vector>
#include <filesystem>
#include <memory>
#include "../../../DataBases/LocalDB/include/LocalDB.h"
struct FileMeta {
        int id;
        std::string fileName;
        int fileSize;
        int version;
        int quantityChunks;
};


struct LocalDB {};

struct IFileDB {};


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
    Indexer (std::shared_ptr<UserDB> localDB);
    FileMeta createFile(const std::filesystem::path& path, size_t chunksCnt) override;
    FileMeta modifyFile(const std::filesystem::path& path, size_t chunksCnt) override;
    FileMeta renameFile(const std::filesystem::path& oldPath,
        const std::filesystem::path& newPath) override;
    FileMeta deleteFile(const std::filesystem::path& path) override;
    FileMeta getFileInfo(const std::filesystem::path& path) override;
private:
    std::shared_ptr<LocalDB> LocalDataBase;
    std::shared_ptr<IFileDB> FileDB;
};

