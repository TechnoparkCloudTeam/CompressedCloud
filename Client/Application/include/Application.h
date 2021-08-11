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
class Application
{
public:
    Application(
        std::shared_ptr<IClientNetwork> network,
        std::shared_ptr<IIndexer> indexer,
        std::shared_ptr<IRequestCoordinator> requestCoordinator);
    ~Application();
    void login(const std::string &login, const std::string &pass);
    void registerUser(const std::string &login, const std::string &pass);
    bool isLogin();
    void downloadFile(const std::string &fileName);
    void downloadFileFriend(const std::string &friendName, const std::string &file);
    void sendFile(const FileMeta &fileinfo);
    void deleteFile(const std::string &fileName);
    void runWatcher();
    void stopWatcher();
    void addFriend(const std::string &friendLogin);

private:
    bool isWatcherRunning;
    std::string synchFolder;
    std::string Login;
    std::string Password;
    void checkPassword();
    void initWatcher();
    std::shared_ptr<IClientNetwork> Network;
    std::shared_ptr<IIndexer> Index;
    WatcherNotifierBuilder Watcher;
    std::thread WatcherThread;
    bool isLoggedIn;
    std::shared_ptr<IRequestCoordinator> RequestCoord;
};
