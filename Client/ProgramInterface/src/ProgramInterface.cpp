#include "../include/ProgramInterface.h"
#include <string>

ProgramInterface::ProgramInterface(std::shared_ptr<Application> app) : app(app) {
};


void ProgramInterface::run() {
    std::string input;
    std::cout << "CompressedCloud initiated\nEnter <help> command to learn about the commands\n";
    while (1) {
        std::cout << ":/ ";
        getline(std::cin, input);
        if (input == "help") {
            std::cout << "Commands: <help> - info about commands\n";
            std::cout << "          <synchronize> - download latest version from server\n";
            std::cout << "          <login> login into the system \n";
            std::cout << "          <register> register on server \n";
            std::cout << "          <getFile> - download file from cloud\n";
            std::cout << "          <addFriend> - add friend\n";
            std::cout << "          <getFileFriend> - download file from friend\n";
            std::cout << "          <removeFile> - remote file in cloud\n";
            std::cout << "          <quit> - shutdown application\n";
            //std::cout << "          <currentDir> - show current directory";
        } else if (input == "login") {

            std::string login;
            std::string password;
            do {
                std::cout << "Enter login: ";
                getline(std::cin, login);
            } while (login.empty());

            do {
                std::cout << "Enter password: ";
                getline(std::cin, password);
            } while (password.empty());
            app->login(login, password);

        } else if (input == "register"){

            std::string login;
            std::string password;
            do {
                std::cout << "Enter login: ";
                getline(std::cin, login);
            } while (login.empty());

            do {
                std::cout << "Enter password: ";
                getline(std::cin, password);
            } while (password.empty());
            app->registerUser(login, password);

        } else if (input == "synchronize") {

            if (app->isLogin()) {
                app->synchronize();
                std::cout << "Latest version is set\n";
            } else {
                std::cout << "Can't synchronize, you are not logged in the system, use <login> or <register>\n";
            }

        } else if (input == "quit") {
            std::cout << "Quitting application\n";
            break;
        } else if (input == "stop") {
            app->stopWatcher();
        } else if (input == "run") {
            app->runWatcher();
        } else if (input == "getFile") {
            std::string FileName;
            std::cin >> FileName;
            std::cout<<"cin correct";
            app->downloadFile(FileName);
        } else if (input == "addFriend") {
            std::cout << "Enter friend's login: ";
            std::string FriendName;
            std::cin >> FriendName;
            app->addFriend(FriendName);
        } else if (input =="getFileFriend") {
            std::cout << "Enter Friend";
            std::string FriendName;
            std::cin >> FriendName;
            std::cout<< "Enter file name";
            std::string FileName;
            std::cin >> FileName;
            app->downloadFileFriend(FriendName, FileName);
        } else if (input == "removeFile") {
            std::cout<<"Enter file name: ";
            std::string FileName;
            std::cin >> FileName;
            app->deleteFile(FileName);
        } else {
            std::cout << "Unknown command enter <help> command to learn about the commands\n";
        }
    }

}
