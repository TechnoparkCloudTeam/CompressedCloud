#include "../include/ProgramInterface.h"
#include <string>

ProgramInterface::ProgramInterface(std::shared_ptr<Application> app) : app(app) {
};

void ProgramInterface::run() {
    std::string input;
    std::cout << "CompressedCloud initiated\nEnter <help> command to learn about the commands\n";
    while (1) {
        std::cin >> input;
        if (input == "help") {
            std::cout << "Commands: <help> - info about commands\n";
            std::cout << "          <synchronize> - download latest version from server\n";
            std::cout << "          <login> login into the system \n";
            std::cout << "          <register> register on server \n";
            std::cout << "          <quit> - shutdown application\n";
            //std::cout << "          <currentDir> - show current directory";
        } else if (input == "login") {

            std::string login;
            std::string password;
            std::cout << "Enter login: ";
            std::cin >> login;
            std::cout << "\nEnter password: ";
            std::cin >> password;
            app->login(login, password);

        } else if (input == "register"){

            std::string login;
            std::string password;
            std::cout << "Enter login: ";
            std::cin >> login;
            std::cout << "\nEnter password: ";
            std::cin >> password;
            app->registerUser(login, password);
            std::cout << "User registered\n";

        } else if (input == "synchronize") {

            if (app->isLogin()) {
                app->synchronize();
                std::cout << "Latest version is set\n";
            } else {
                std::cout << "Can't synchronize you are not logged in the system, use <login> or <register>\n";
            }

        } else if (input == "quit") {

            std::cout << "Quitting application\n";
            exit(0);

        } else {
            std::cout << "Unknown command enter <help> command to learn about the commands\n";
        }
    }
}
