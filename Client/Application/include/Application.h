#pragma once
#include <memory>
#include <string>
#include "../../Indexer/include/Indexer.h"
#include "../../../Server/ServerFileStorage/fileStorageWorker/include/FileStorageWorker.h"
#include "../../../DataBases/LocalDB/include/LocalDB.h"
#include "../../../Server/ClientNetwork/include/ClientNetwork.h"
#include "../../../Server/config.h"
class Application {
public:
    Application(
     std::shared_ptr<ClientNetwork> network,
     std::shared_ptr<UserDB> users,
     std::shared_ptr<FileDB> files);

    void login(std::string login, std::string pass);
    void registerUser(std::string login, std::string pass);
    void changePassword();
    bool isLogin();
    void logOut();
    void downloadFile();
    void sendFile();
    void renameFile();
    void deleteFile();
    void createFile();
    void synchronize();
    void setSyncFolder(const std::string& synchFolder);
    void runWatcher();
    void stopWatcher();
private:
    std::string synchFolder;
    std::string Login;
    std::string Password;
    void checkPassword();
    std::shared_ptr<FileStorageWorker> FileWorker;
    std::shared_ptr<ClientNetwork> Network;
    std::shared_ptr<UserDB> Users;
    std::shared_ptr<FileDB> Files;
};