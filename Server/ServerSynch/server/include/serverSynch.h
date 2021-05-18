#pragma once

#include <boost/asio.hpp>
#include <vector>
#include <thread>
#include <string>
#include "../../../../DataBases/PostgresDB/UserDB/include/UserDB.h"
#include <boost/enable_shared_from_this.hpp>

#include "../../../../DataBases/PostgresDB/UserDB/include/UserInfo.h"
#include "../../connection/include/connectionSynch.h"

namespace sServer
{
    class Server
    {
    public:
        explicit Server(int port, std::shared_ptr<UsersDB> postgres_sqldb12/* , const std::string& filed */);
         
        ~Server();
        
        void run();
        
        void stop();
        
        void waitForClientConnection();

    private:
        std::vector<std::shared_ptr<Connection>> allConnection;
        
        boost::asio::io_service io_service_;
        
        boost::asio::ip::tcp::acceptor acceptor_;
        
        boost::asio::ip::tcp::socket socket_;
        
        std::shared_ptr<UsersDB> postgres_sqldb1;
    };

}