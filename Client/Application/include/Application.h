#pragma once
#include <memory>
#include <string>
#include "../../Indexer/include/Indexer.h"
#include "../../../Server/ServerFileStorage/fileStorageWorker/include/FileStorageWorker.h"
#include "../../../DataBases/LocalDB/include/LocalDB.h"
#include "../../../Server/ClientNetwork/include/ClientNetwork.h"
#include "../../../Server/config.h"
#include "../../Watcher/include/WatcherNotifierBuilder.h"
class Application {
public:
    Application(
     std::shared_ptr<ClientNetwork> network,
     std::shared_ptr<UserDB> users,
     std::shared_ptr<FileDB> files);
    ~Application();
    void login(std::string login, std::string pass);
    void registerUser(std::string login, std::string pass);
    void changePassword();
    bool isLogin();
    void logOut();
    void downloadFile(const std::string& fileName);
    void sendFile(const FileMeta &fileinfo);
    void renameFile();
    void deleteFile();
    void createFile(const std::string fileName, const char* buffer);
    void synchronize();
    void setSyncFolder(const std::string& synchFolder);
    void runWatcher();
    void stopWatcher();
    void addFriend(const std::string& friendLogin);
private:
    std::string synchFolder;
    std::string Login;
    std::string Password;
    void checkPassword();
    void initWatcher();
    std::shared_ptr<ClientNetwork> Network;
    std::shared_ptr<UserDB> Users;
    std::shared_ptr<FileDB> Files;
    WatcherNotifierBuilder Watcher;
    std::thread WatcherThread;
    bool isLoggedIn;
};

std::string GetCurrentPath();