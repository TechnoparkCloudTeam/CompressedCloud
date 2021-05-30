#pragma once
#include <memory>
#include <string>
#include <thread>
#include <filesystem>
#include <chrono>
#include <iostream>


#include "FileStorageWorker.h"
#include "LocalDB.h"
#include "ClientNetwork.h"
#include "WatcherNotifierBuilder.h"
#include "RequestCoordinator.h"
#include "Indexer.h"
#include "RequestStatus.h"
class Application {
public:
    Application(
     std::shared_ptr<ClientNetwork> network,
     std::shared_ptr<Indexer> indexer,
     std::shared_ptr<RequestCoordinator> requestCoordinator);
    ~Application();
    void login(std::string login, std::string pass);
    void registerUser(std::string login, std::string pass);
    bool isLogin();
    void downloadFile(const std::string& fileName);
    void downloadFileFriend(const std::string& friendName, const std::string& file);
    void sendFile(const FileMeta &fileinfo);
    void deleteFile(const std::string& fileName);
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
    std::shared_ptr<Indexer> Index;
    WatcherNotifierBuilder Watcher;
    std::thread WatcherThread;
    bool isLoggedIn;
    std::shared_ptr<RequestCoordinator> RequestCoord;
};
