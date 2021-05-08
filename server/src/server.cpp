#include <iostream>
#include "server.h"
fsServer::Server::Server(const std::string& port)
    : io_service_(),
      acceptor_(io_service_),
      socket_(io_service_)
{
    boost::asio::ip::tcp::resolver resolver(io_service_);
    boost::asio::ip::tcp::endpoint endpoint = *resolver.resolve({"127.0.0.1", port});
    acceptor_.open(endpoint.protocol());
    acceptor_.set_option(boost::asio::ip::tcp::acceptor::reuse_address(true));
    acceptor_.bind(endpoint);
    acceptor_.listen();
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
    acceptor_.async_accept([this](std::error_code er,
                                  boost::asio::ip::tcp::socket socket_) {
        if (!er)
        {
            std::cout << "Connect " << socket_.remote_endpoint() << std::endl;
            std::shared_ptr<Connection> newConnect =
                std::make_shared<Connection>(std::move(socket_));
            
            allConnection.push_back(std::move(newConnect));
            allConnection[allConnection.size() - 1]->start();
        }
        waitForClientConnection();
    });
}