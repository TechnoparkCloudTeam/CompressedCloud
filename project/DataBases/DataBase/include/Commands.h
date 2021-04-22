#include <memory>
#include "MetaDB.h"
#include "UserDB.h"

class Commands {
public:
        void sendFileInfo(std::string &query);
        void sendNewFileInfo(std::string &query);
        void loginUser(std::string &query);
        void sendFileInfo(std::string &query);
        void sendUserDirInfo(std::string &query);
private:
        std:shared_ptr<MetaDB> metaDB;
        std::shared_ptr<UserDB> userDB;
        connectToDataBase();
};
