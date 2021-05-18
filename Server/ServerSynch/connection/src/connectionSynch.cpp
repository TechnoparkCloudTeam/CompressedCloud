#include <iostream>
#include "connectionSynch.h"
#include "PostgreSQLDB.h"
#include "../../../../DataBases/PostgresDB/UserDB/include/UserDB.h"
#include "../../../../DataBases/PostgresDB/MetaDB/include/MetaDB.h"
#include "../../../../DataBases/PostgresDB/UserDB/include/UserInfo.h"
#include "../../../../DataBases/PostgresDB/MetaDB/include/FileInfo.h"
enum ServerSyncho
{
    OK = 0,
    BAD = 1,
    REGISTRATION = 2,
    AUTORIZATION = 3,
    EXERTFILE = 4,
};

Connection::Connection(boost::asio::ip::tcp::socket socket_, std::shared_ptr<UsersDB> postgres_sqldb12) : socket_(std::move(socket_)),
                                                                                                          postgres_sqldb1(postgres_sqldb12)
{
}

void Connection::stop()
{
    socket_.close();
}

void Connection::start()
{
    socket_.async_read_some(boost::asio::buffer(data_),
                            boost::bind(&Connection::read, shared_from_this()));
}
void Connection::read()
{
    messageFS::Request writeRequest;
    messageFS::Request readRequest;

    readRequest.ParseFromString(data_);
    std::cout << readRequest.id() << " " << readRequest.name() << std::endl;

    switch (readRequest.id())
    {
    case ServerSyncho::REGISTRATION:
    {
        std::cout << "User has register " << readRequest.name() << std::endl;
        UserInfo us;
        us.login = readRequest.name();
        us.password = readRequest.password();
        postgres_sqldb1->Registration(us);
        writeRequest.set_id(ServerSyncho::OK);
        break;
    }
    case ServerSyncho::AUTORIZATION:
    {
        std::cout << "User autorizated " << readRequest.name() << std::endl;
        UserInfo us1;
        us1.login = readRequest.name();
        us1.password = readRequest.password();
        bool isUser =  postgres_sqldb1->Login(us1);
        if(isUser)
            writeRequest.set_id(ServerSyncho::OK);
        else
            writeRequest.set_id(ServerSyncho::BAD);
    }
    default:
        break;

        std::string ans_string;
        writeRequest.SerializePartialToString(&ans_string);
        boost::asio::async_write(socket_, boost::asio::buffer(ans_string, 250), boost::bind(&Connection::write, shared_from_this()));
    }
}
void Connection::write()
{
    std::cout << "writing" << std::endl;
    socket_.async_read_some(boost::asio::buffer(data_),
                            boost::bind(&Connection::read, shared_from_this()));
}
