#include <vector>
#include <memory>
#include <string>
#include "LocalDB.h"

struct FileMeta {
        int id;
        std::string fileName;
        int fileSize;
        int version;
        int quantityChunks;
};

class FileDB {
public:
        void renameFile(FileMeta &file);
        void addFile(FileMeta &file);
        void deleteFile(FileMeta &file);
        void updateFile(FileMeta &file);
        FileMeta selectFile(const int &fileId);
        FileMeta getFile(const std::string &path, const std::string &name);
        int getFileId(const std::string &path, const std::string &name);
        std::vector<FileMeta> selectAllFiles();
        void updateSynchFolder(const std::string  &newFolder);
private:
        FileMeta fileMeta;
        std::shared_ptr<LocalDB> localDB;
};
