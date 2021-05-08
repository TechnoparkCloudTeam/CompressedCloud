#include <iostream>
#include "server.h"
fsServer::Server::Server(const std::string& port/* , const std::string& filed */)
    : io_service_(),
      acceptor_(io_service_, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 8888)),
      socket_(io_service_)
      //fsworker("/home/lyalyashechka/TP/c_c++/main server/build")
{
    waitForClientConnection();
}

fsServer::Server::~Server()
{
    stop();
}

void fsServer::Server::run()
{
    std::cout << "Run" << std::endl;
    io_service_.run();
}

void fsServer::Server::stop()
{
    io_service_.stop();
    std::cout << "Stop" << std::endl;
}

void fsServer::Server::waitForClientConnection()
{
    acceptor_.async_accept(socket_, [this](boost::system::error_code er) {
        if (!er)
        {
            std::cout << "Connect " << socket_.remote_endpoint() << std::endl;
            std::make_shared<Connection>(std::move(socket_))->start();
        }
        waitForClientConnection();
    });
}