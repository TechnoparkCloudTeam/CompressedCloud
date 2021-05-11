#include "Application.h"


Application::Application(std::shared_ptr<IWatcher> watch,
     std::shared_ptr<I_Indexer> index, std::shared_ptr<ClientNetwork> network,
     std::shared_ptr<FileStorageWorker> fileWorker) : 
     Watcher(watch),
     Indexer(index),
     NetworkCommunication(network),
     FileWorker(fileWorker) {}


void Application::login() {
    //ClientNetwork.start();
    //ClientNetwork.writeMessage();
    //ClientNetwork.readMessage();
    //ClientNetwork.handleRead();
    return;
}
void Application::registerUser() {
    //ClientNetwork.start();
    //ClientNetwork.writeMessage();
    //ClientNetwork.readMessage();
    //ClientNetwork.handleRead();
    //UserDB.connect();
    //UserDB.addUser();
    //UserDB.disconnect();
    return;
}
void Application::changePassword() {
    return;
}
bool Application::isLogin() {
    return (this->Login != "");
}
void Application::logOut() {
    //ClientNetwork.start();
    //ClientNetwork.writeMessage();
    //ClientNetwork.readMessage();
    this->Login = "";
    this->Password = "";
    return;
}
void Application::downloadFile() {
    //ClientNetwork.start();
    //ClientNetwork.writeMessage();
    //ClientNetwork.readMessage();
    Watcher->shutdown();
    //ClientNetwork.handleRead();
    //fileWorker->createFile();
    Watcher->run(synchFolder);
    return;
}
void Application::sendFile() {
    //ClientNetwork.start();
    //ClientNetwork.writeMessage();
    //ClientNetwork.readMessage();
    //ClientNetwork.handleRead();
    return;
}
void Application::renameFile() {
    
    //ClientNetwork.start();
    //ClientNetwork.writeMessage();
    //ClientNetwork.readMessage();
    //ClientNetwork.handleRead();
    return;
}
void Application::deleteFile() {
    //ClientNetwork.start();
    //ClientNetwork.writeMessage();
    //ClientNetwork.readMessage();
    //ClientNetwork.handleRead();
    //fileWorker->removeFileFromDir();
    return;
}

void Application::createFile() {
    return;
}
void Application::checkPassword() {
    return;
}
void Application::runWatcher() {
    Watcher->run(synchFolder);
}
void Application::stopWatcher() {
    Watcher->shutdown();
}
void Application::synchronize() {
    downloadFile();
}