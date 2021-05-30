#include <iostream>
#include "server.h"

fsServer::Server::Server(int port)
    : io_service_(),
      acceptor_(io_service_, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)),
      socket_(io_service_)
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
    acceptor_.async_accept(socket_, [this](boost::system::error_code er)
                           {
                               if (!er)
                               {
                                   std::cout << "Connect " << socket_.remote_endpoint() << std::endl;
                                   std::make_shared<Connection>(std::move(socket_))->start();
                               }
                               waitForClientConnection();
                           });
}