#pragma once

#include <boost/asio.hpp>
#include <vector>
#include <thread>
#include <string>
#include "connection.h"

namespace fsServer
{
    class Server
    {
    public:
        explicit Server(const std::string& port);
        
        ~Server();
        
        void run();
        
        void stop();
        
        void waitForClientConnection();

    private:
        std::vector<std::shared_ptr<Connection>> allConnection;
        
        boost::asio::io_service io_service_;
        
        boost::asio::ip::tcp::acceptor acceptor_;
        
        boost::asio::ip::tcp::socket socket_;
        
        std::thread t_contex;
    };

}