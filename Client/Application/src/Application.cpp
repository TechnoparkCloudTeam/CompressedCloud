#include "Application.h"

Application::Application(
     std::shared_ptr<ClientNetwork> network,
     std::shared_ptr<UserDB> users,
     std::shared_ptr<FileDB> files) :
     Network(network),
     Users(users),
     Files(files),
     isLoggedIn(false) {

}

void Application::login(std::string login, std::string pass) {
    messageFS::Request req;
    req.set_name(login);
    req.set_password(pass);
    req.set_id(ServerSyncho::AUTORIZATION);
    std::string msg;
	boost::system::error_code ec;
    req.SerializePartialToString(&msg);
	Network->writeMessageToS(ec, msg);
    isLoggedIn = Network->IsLogin();
}

void Application::registerUser(std::string login, std::string pass) {
    messageFS::Request req;
    req.set_name(login);
    req.set_password(pass);
    req.set_id(ServerSyncho::REGISTRATION);
    std::string msg;
	boost::system::error_code ec;
    req.SerializePartialToString(&msg);
	Network->writeMessageToS(ec, msg);
    User user;
    user.deviceName = "PC";
    user.synchFolder = "/home/ilya/test";
    user.login = login;
    user.password = pass;
    Users->addUser(user);
}
void Application::changePassword() {
    return;
}
bool Application::isLogin() {
    return isLoggedIn;
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
    //Watcher->shutdown();
    //ClientNetwork.handleRead();
    //fileWorker->createFile();
    //Watcher->run(synchFolder);
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
    //ClientNetwork.start();
    //ClientNetwork.writeMessage();
    //ClientNetwork.readMessage();
    //ClientNetwork.handleRead();
    return;
}
void Application::checkPassword() {
    return;
}
void Application::runWatcher() {
    Watcher->run();
}
void Application::stopWatcher() {
    //Watcher->shutdown();
}
void Application::synchronize() {
    downloadFile();
}

void Application::setSyncFolder(const std::string& synchFolder) {
    this->synchFolder = synchFolder;
}
