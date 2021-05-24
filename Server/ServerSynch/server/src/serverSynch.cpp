#include <iostream>
#include "serverSynch.h"

sServer::Server::Server(int port, std::shared_ptr<UsersDB> postgres_sqldb12, std::shared_ptr<MetaDataDB> postgres_sqldb_file)
    : io_service_(),
      acceptor_(io_service_, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)),
      socket_(io_service_),
      postgres_sqldb1(postgres_sqldb12),
      postgres_sqldb_file(postgres_sqldb_file)
{
    waitForClientConnection();
}

sServer::Server::~Server()
{
    stop();
}

void sServer::Server::run()
{
    std::cout << "Run" << std::endl;
    io_service_.run();
}

void sServer::Server::stop()
{
    io_service_.stop();
    std::cout << "Stop" << std::endl;
}

void sServer::Server::waitForClientConnection()
{
    acceptor_.async_accept(socket_, [this](boost::system::error_code er) {
        if (!er)
        {
            std::cout << "Connect " << socket_.remote_endpoint() << std::endl;

            std::make_shared<Connection>(std::move(socket_),postgres_sqldb1, postgres_sqldb_file)->start();
        }
        waitForClientConnection();
    });
}