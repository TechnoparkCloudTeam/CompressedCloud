#include <string>
#include <vector>

struct  FileInfo {

};

struct UserDate {
        int userId;
        std::string date;
};

class IMetaDB {
public:
        virtual void addNewFileInfo(const FileInfo &file) = 0;
        virtual void changeFileInfo(FileInfo &file) = 0;
        virtual std::vector<FileInfo>  getUserFileInfo(const UserDate &user) = 0;
};

