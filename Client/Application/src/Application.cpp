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
    return (fileName.find(".goutputstream") != std::string::npos);
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
    //runWatcher();
    WatcherThread = std::thread([&]()
                                { Watcher.run(); });
    //WatcherThread.detach();
}

void Application::login(std::string login, std::string pass)
{
    this->Login = login;
    this->Password = pass;
    messageFS::Request req;
    req.set_name(login);
    req.set_password(pass);
    req.set_id(ServerSyncho::AUTORIZATION);
    std::string msg;
    req.SerializePartialToString(&msg);
    Network->writeMessageToS(msg);
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
    User user;
    user.deviceName = "PC";
    user.synchFolder = synchFolder;
    user.login = login;
    user.password = pass;
    Users->addUser(user);
    req.SerializePartialToString(&msg);
    Network->writeMessageToS(msg);
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
}
void Application::downloadFile(const std::string &fileName)
{
    messageFS::Request req;
    req.set_name(Login);
    req.set_password(Password);
    req.set_id(ServerFS::DOWNLOADFILE);
    req.set_filename(fileName);
    std::string msg;
    req.SerializePartialToString(&msg);
    Network->writeMessageToFS(msg);
}
void Application::sendFile(const FileMeta &fileinfo)
{
    messageFS::Request req;

    req.set_name(Login);
    req.set_password(Password);
    req.set_id(ServerFS::SENDFILE);
    req.set_filename(fileinfo.fileName);
    req.set_filepath(fileinfo.filePath);
    req.set_fileextention(fileinfo.fileExtention);
    std::ifstream file(fileinfo.filePath, std::ofstream::binary);
    file.seekg(0, file.end);
    int64_t size = file.tellg();
    req.set_filesize(size);
    file.seekg(0);
    char *buffer = new char[size];
    file.read(buffer, size);
    req.set_file(std::string(buffer, size));
    delete[] buffer;
    req.set_filesize(size);
    std::string msg;
    req.SerializePartialToString(&msg);
    Network->writeMessageToFS(msg);
}

void Application::downloadFileFriend(const std::string& friendName, const std::string& file)
{
    messageFS::Request req;
    req.set_id(ServerSyncho::CHECKFRIENDANDFILE);
    req.set_name(Login);
    req.set_loginfriend(friendName);
    req.set_filename(file);
    std::string msg;
    req.SerializePartialToString(&msg);
    Network->writeMessageToS(msg);
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

void Application::createFile(const std::string fileName, const char *buffer)
{
    return;
}
void Application::checkPassword()
{
    return;
}
void Application::runWatcher()
{
    Watcher.runAfterShutDown();
    WatcherThread = std::thread([&]()
                                { Watcher.run(); });
    //WatcherThread.detach();
}
void Application::stopWatcher()
{
    Watcher.stop();
    WatcherThread.join();
}
void Application::synchronize()
{
    //downloadFile();
}

void Application::setSyncFolder(const std::string &synchFolder)
{
    this->synchFolder = synchFolder;
}

void Application::initWatcher()
{
    auto handleNotification = [&](WatcherNotification notification)
    {
        if (!isTmpFile(notification.Path.filename()))
        {
            //std::cout << "Event " << notification.Event << " on " << notification.Path << " at " << notification.Time.time_since_epoch().count() << " was triggered.\n";
            FileMeta f;
            f.fileName = notification.Path.filename();
            f.fileExtention = notification.Path.extension();
            f.createDate = GetCurrentTime();
            f.updateDate = GetCurrentTime();
            f.isDownload = false;
            f.version;
            f.chunksCount = 0;
            f.filePath = notification.Path;
            f.fileSize = 1000;
            switch (notification.Event)
            {
            case InotifyEvent::_create:
            {
                Files->addFile(f);
                Files->updateFile(f);
                break;
            }
            case InotifyEvent::_close_write:
            {
                Files->updateFile(f);

                if (isLogin())
                {
                    sendFile(f);
                }
                break;
            }
            case (InotifyEvent::_move & InotifyEvent::_moved_from):
            {
                std::cout << "removing file";
                Files->deleteFile(f.fileId);
                break;
            }
            default:
                break;
            }
        }
    };

    auto handleUnexpectedNotification = [](WatcherNotification notification)
    {
    };
    auto events = {InotifyEvent::_open | InotifyEvent::_is_dir,
                   InotifyEvent::_access,
                   InotifyEvent::_create,
                   InotifyEvent::_modify,
                   InotifyEvent::_remove,
                   InotifyEvent::_close_write,
                   //InotifyEvent::_move | InotifyEvent::_moved_from,
                   InotifyEvent::_move, InotifyEvent::_moved_from,
                   InotifyEvent::_moved_to};

    Watcher = BuildWatcherNotifier()
                  .watchPathRecursively(synchFolder)
                  .ignoreFileOnce("fileIgnoredOnce")
                  .onEvents(events, handleNotification)
                  .onUnexpectedEvent(handleUnexpectedNotification);
}

void Application::addFriend(const std::string& friendLogin) {
    messageFS::Request req;
    req.set_name(Login);
    req.set_loginfriend(friendLogin);
    req.set_id(ServerSyncho::ADDFRIEND);
    std::string msg;
    req.SerializePartialToString(&msg);
    Network->writeMessageToS(msg);
}

Application::~Application()
{
}

