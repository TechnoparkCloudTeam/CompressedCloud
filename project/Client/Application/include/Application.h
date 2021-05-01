#pragma once
#include "../../ProgramInterface/include/ProgramInterface.h"
#include "../../Chunker/include/Chunker.h"
#include "../../Watcher/include/Watcher.h"
#include "../../Indexer/include/Indexer.h"
#include "ClientNetwork.h"
#include <memory>


class Application {
public:
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
    bool listeningWatcher();
private:
    void checkPassword();
    void runWatcher();
    void stopWatcher();
    std::shared_ptr<IChunker> Chunker;
    std::shared_ptr<IWatcher> Watcher;
    std::shared_ptr<I_Indexer> Indexer;
    std::shared_ptr<ProgramInterface> Interface;
    std::shared_ptr<ClientNetwork> NetworkCommunication;
};