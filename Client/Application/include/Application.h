#pragma once
//#include "../../Watcher/include/Watcher.h"
#include "../../Indexer/include/Indexer.h"
#include "../../../Server/ServerFileStorage/fileStorageWorker/include/FileStorageWorker.h"
#include <memory>
#include <string>
class Watcher {};

struct ClientNetwork {};

class Application {
public:
    Application(std::shared_ptr<Watcher> watch,
     std::shared_ptr<I_Indexer> index, std::shared_ptr<ClientNetwork> network);
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
    std::shared_ptr<Watcher> watcher;
    std::shared_ptr<I_Indexer> Indexer;
    std::shared_ptr<ClientNetwork> NetworkCommunication;
    std::shared_ptr<FileStorageWorker> FileWorker;
};