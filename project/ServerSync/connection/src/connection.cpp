#include <iostream>
#include "connection.h"

Connection::Connection(boost::asio::ip::tcp::socket socket_) : socket_(std::move(socket_))
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
    
    messageFS::Request req;
    req.ParseFromString(data_);
    std::cout << req.id() << " " << req.name() << " " << req.file() << std::endl;

    if (req.id() == 1)
    {
        std::cout << "Creating folder for user: " << req.name() << std::endl;
        
    }
    if (req.id() == 2)
    {
        std::cout << "Deleted file from user: " << req.name() << std::endl;
      
    }
    if (req.id() == 3)
    {
        std::cout << "Got file from user: " << req.name() << std::endl;
      
    }
    messageFS::Request ans;
    ans.set_id(1);
    std::string ans_string;
    ans.SerializePartialToString(&ans_string);
    boost::asio::async_write(socket_, boost::asio::buffer(ans_string, 100), boost::bind(&Connection::write, shared_from_this()));
}
void Connection::write()
{
    std::cout<<"writing"<<std::endl;
    socket_.async_read_some(boost::asio::buffer(data_),
                            boost::bind(&Connection::read, shared_from_this()));
} 