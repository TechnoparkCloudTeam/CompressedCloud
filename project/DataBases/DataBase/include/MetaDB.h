#include "IMetaDB.h"
#include "PostgresDB.h"

class MetaDB : public IMetaDB, public PostgresDB {
        void addNewFileInfo(const FileInfo &file) override;
        void changeFileInfo(FileInfo &file) override;
        std::vector<FileInfo> getUserFileInfo(const UserDate &user) override;
};
