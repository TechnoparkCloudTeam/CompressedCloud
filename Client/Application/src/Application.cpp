#include "Application.h"


bool isTmpFile(const std::string &fileName)
{
    return (fileName.find(".goutputstream") != std::string::npos);
}

Application::Application(
    std::shared_ptr<ClientNetwork> network,
    std::shared_ptr<Indexer> indexer,
    std::shared_ptr<RequestCoordinator> requestCoordinator) :
        Network(network),
        Index(indexer),
        isLoggedIn(false),
        RequestCoord(requestCoordinator)
{    
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
    isLoggedIn = RequestCoord->waitCancelDownload();
    if (isLoggedIn)
    {
        std::cout << "Logged in successfully\n";
        synchFolder = login;
        runWatcher();
    }
    else
    {
        std::cout << "Can't login\n";
    }
}

void Application::registerUser(std::string login, std::string pass)
{
    messageFS::Request req;
    req.set_name(login);
    req.set_password(pass);
    req.set_id(ServerSyncho::REGISTRATION);
    std::string msg; 
    
    req.SerializePartialToString(&msg);
    Network->writeMessageToS(msg);
    RequestCoord->waitCancelDownload();
    std::cout << "Registerd succesfully\n";
    Index->AddUser(login, pass);
    std::filesystem::create_directory(login);
    
}

bool Application::isLogin()
{
    return isLoggedIn;
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
    stopWatcher();
    Network->writeMessageToFS(msg);
    RequestCoord->waitCancelDownload();
    runWatcher();
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

void Application::downloadFileFriend(const std::string &friendName, const std::string &file)
{
    messageFS::Request req;
    req.set_id(ServerSyncho::CHECKFRIENDANDFILE);
    req.set_name(Login);
    req.set_loginfriend(friendName);
    req.set_filename(file);
    std::string msg;
    req.SerializePartialToString(&msg);
    stopWatcher();
    Network->writeMessageToS(msg);
    RequestCoord->waitCancelDownload();
    runWatcher();
}
void Application::deleteFile(const std::string& fileName)
{
    messageFS::Request req;
    req.set_id(ServerFS::DELETEFILE);
    req.set_name(Login);
    req.set_filename(fileName);
    std::string msg;
    req.SerializePartialToString(&msg);
    Network->writeMessageToFS(msg);
    return;
}

void Application::runWatcher()
{
    initWatcher();
    WatcherThread = std::thread([&]()
                                { Watcher.run(); });
}
void Application::stopWatcher()
{
    Watcher.stop();
    WatcherThread.join();
}

void Application::initWatcher()
{
    auto handleNotification = [&](WatcherNotification notification)
    {
        if (!isTmpFile(notification.Path.filename()))
        {
            std::cout << "Event " << notification.Event << " on " << notification.Path << " at " << notification.Time.time_since_epoch().count() << " was triggered.\n";

            switch (notification.Event)
            {
            case InotifyEvent::_create:
            {
                Index->createFile(notification.Path);
                sendFile(Index->GetFileInfo(notification.Path));
                break;
            }
            case InotifyEvent::_close_write:
            {
                Index->createFile(notification.Path);
                Index->modifyFile(notification.Path, 1);
                sendFile(Index->GetFileInfo(notification.Path));
                break;
            }
            case (InotifyEvent::_move & InotifyEvent::_moved_from):
            {
                Index->deleteFile(notification.Path);
                break;
            }
            default:
                break;
            }
        }
    };

    auto handleUnexpectedNotification = [](WatcherNotification notification) {
    };
    auto events = {InotifyEvent::_open | InotifyEvent::_is_dir,
                   InotifyEvent::_access,
                   //InotifyEvent::_create,
                   InotifyEvent::_modify,
                   InotifyEvent::_remove,
                   InotifyEvent::_close_write,
                   InotifyEvent::_move,
                   InotifyEvent::_moved_from,
                   InotifyEvent::_moved_to};

    Watcher = BuildWatcherNotifier()
                  .watchPathRecursively(synchFolder)
                  .ignoreFileOnce("fileIgnoredOnce")
                  .onEvents(events, handleNotification)
                  .onUnexpectedEvent(handleUnexpectedNotification);
}

void Application::addFriend(const std::string &friendLogin)
{
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
