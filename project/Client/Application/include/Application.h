#pragma once
#include "../../Watcher/include/Watcher.h"
#include "../../Indexer/include/Indexer.h"
#include "../../../Server/fileStorageWorker/include/FileStorageWorker.h"
#include <memory>
#include <string>
struct ClientNetwork {};

class Application {
public:
    Application(std::shared_ptr<IWatcher> watch,
     std::shared_ptr<I_Indexer> index, std::shared_ptr<ClientNetwork> network);
    void login();
    void registerUser();
    void changePassword();
    bool isLogin();
    void logOut();
    void downloadFile();
    void sendFile();
    void renameFile();
    void deleteFile();
    void createFile();
    void synchronize();
private:
    std::string synchFolder;
    std::string Login;
    std::string Password;
    void checkPassword();
    void runWatcher();
    void stopWatcher();
    std::shared_ptr<IWatcher> Watcher;
    std::shared_ptr<I_Indexer> Indexer;
    std::shared_ptr<ClientNetwork> NetworkCommunication;
    std::shared_ptr<FileStorageWorker> FileWorker;
};