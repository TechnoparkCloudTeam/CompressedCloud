#include "Application.h"

std::string GetCurrentPath()
{
    std::filesystem::path Path = std::filesystem::current_path();
    return Path.c_str();
}

std::string GetCurrentTime()
{
    auto ttime = time(nullptr);
    auto *local_time = localtime(&ttime);
    std::string lastTMPUpdate = std::to_string(1900 + local_time->tm_year) + "-" + std::to_string(1 + local_time->tm_mon) + "-" + std::to_string(local_time->tm_mday) + " " + std::to_string(local_time->tm_hour) + ":" + std::to_string(local_time->tm_min) + ":" + std::to_string(local_time->tm_sec);
    return lastTMPUpdate;
}

bool isTmpFile(const std::string &fileName)
{
    return (fileName.find(".goutputstream") == std::string::npos);
}

Application::Application(
    std::shared_ptr<ClientNetwork> network,
    std::shared_ptr<UserDB> users,
    std::shared_ptr<FileDB> files) : Network(network),
                                     Users(users),
                                     Files(files),
                                     isLoggedIn(false)
{
    synchFolder = GetCurrentPath() + "/SynchFolder";
    std::filesystem::create_directories(synchFolder);
    initWatcher();
}

void Application::login(std::string login, std::string pass)
{
    messageFS::Request req;
    req.set_name(login);
    req.set_password(pass);
    req.set_id(ServerSyncho::AUTORIZATION);
    std::string msg;
    boost::system::error_code ec;
    req.SerializePartialToString(&msg);
    Network->writeMessageToS(ec, msg);
    sleep(1);
    isLoggedIn = Network->IsLogin();
}

void Application::registerUser(std::string login, std::string pass)
{
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
    user.synchFolder = synchFolder;
    user.login = login;
    user.password = pass;
    Users->addUser(user);
}
void Application::changePassword()
{
    return;
}
bool Application::isLogin()
{
    return isLoggedIn;
}
void Application::logOut()
{
    //ClientNetwork.start();
    //ClientNetwork.writeMessage();
    //ClientNetwork.readMessage();
    this->Login = "";
    this->Password = "";
    return;
}
void Application::downloadFile()
{
    //ClientNetwork.start();
    //ClientNetwork.writeMessage();
    //ClientNetwork.readMessage();
    //Watcher->shutdown();
    //ClientNetwork.handleRead();
    //fileWorker->createFile();
    //Watcher->run(synchFolder);
    return;
}
void Application::sendFile()
{
    //ClientNetwork.start();
    //ClientNetwork.writeMessage();
    //ClientNetwork.readMessage();
    //ClientNetwork.handleRead();
    return;
}
void Application::renameFile()
{

    //ClientNetwork.start();
    //ClientNetwork.writeMessage();
    //ClientNetwork.readMessage();
    //ClientNetwork.handleRead();
    return;
}
void Application::deleteFile()
{
    //ClientNetwork.start();
    //ClientNetwork.writeMessage();
    //ClientNetwork.readMessage();
    //ClientNetwork.handleRead();
    //fileWorker->removeFileFromDir();
    return;
}

void Application::createFile()
{
    //ClientNetwork.start();
    //ClientNetwork.writeMessage();
    //ClientNetwork.readMessage();
    //ClientNetwork.handleRead();
    return;
}
void Application::checkPassword()
{
    return;
}
void Application::runWatcher()
{
    Watcher.run();
}
void Application::stopWatcher()
{
    //Watcher->shutdown();
}
void Application::synchronize()
{
    downloadFile();
}

void Application::setSyncFolder(const std::string &synchFolder)
{
    this->synchFolder = synchFolder;
}

void Application::initWatcher()
{
    auto handleNotification = [&](WatcherNotification notification)
    {
        //std::cout << "Event " << notification.Event << " on " << notification.Path << " at "
          //        << notification.Time.time_since_epoch().count() << " was triggered.\n";

        FileMeta f;
        f.fileName = notification.Path.filename();
        f.fileExtention = notification.Path.extension();
        f.createDate = GetCurrentTime();
        f.updateDate = GetCurrentTime();
        f.isDownload = false;
        f.version = 1;
        f.chunksCount = 0;
        f.filePath = notification.Path;
        f.fileSize = 1000;
        switch (notification.Event)
        {
        case InotifyEvent::_create:
        {
            if (isTmpFile(notification.Path.filename()))
            {
                Files->addFile(f);
                Files->updateFile(f);
            }
            break;
        }
        case InotifyEvent::_modify:
        {
            if (isTmpFile(notification.Path.filename()))
            {
                Files->updateFile(f);
            }
            if (isLogin())
            {
                messageFS::Request req;

                req.set_name(Login);
                req.set_password(Password);
                req.set_id(3);

                std::ifstream file(notification.Path, std::ios_base::binary);

                std::string file_string;
                std::string tmp;
                while (file >> tmp) {
                    file_string += tmp + "\n"; 
                };

                req.set_file(file_string.c_str());

                std::string msg;
                req.SerializePartialToString(&msg);
                boost::system::error_code ec;

                Network->writeMessageToFS(ec, msg);
            }
            break;
        }
        case InotifyEvent::_remove:
        {
            if (isTmpFile(notification.Path.filename()))
            {
                Files->deleteFile(f.fileId);
            }
            break;
        }
        default:
            break;
        }
    };

    auto handleUnexpectedNotification = [](WatcherNotification notification) {};
    auto events = {InotifyEvent::_open | InotifyEvent::_is_dir,
                   InotifyEvent::_access,
                   InotifyEvent::_create,
                   InotifyEvent::_modify,
                   InotifyEvent::_remove,
                   InotifyEvent::_move};

    Watcher = BuildWatcherNotifier()
                  .watchPathRecursively(synchFolder)
                  .ignoreFileOnce("fileIgnoredOnce")
                  .onEvents(events, handleNotification)
                  .onUnexpectedEvent(handleUnexpectedNotification);
}