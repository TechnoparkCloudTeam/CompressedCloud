#pragma once

#include <boost/asio.hpp>
#include <vector>
#include <thread>
#include <string>

#include "connectionSynch.h"
#include "UserDB.h"
#include "UserInfo.h"
#include "MetaDB.h"
#include "FriendDB.h"

namespace sServer
{
    class Server
    {
    public:
        explicit Server(int port, std::shared_ptr<UsersDB> postgres_sqldb12, std::shared_ptr<MetaDataDB> postgres_sqldb_file,
         std::shared_ptr<FriendDB> postgres_sqldb_friend);

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

        std::shared_ptr<MetaDataDB> postgres_sqldb_file;

        std::shared_ptr<FriendDB> postgres_sqldb_friends;
    };

}