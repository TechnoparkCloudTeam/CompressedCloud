#include <iostream>
#include "connection.h"

Connection::Connection(boost::asio::ip::tcp::socket socket_) : socket_(std::move(socket_)) {
    
}

void Connection::start()
{
    read();
}


void Connection::stop()
{
    socket_.close();
}


void Connection::read()
{
    
    auto self(shared_from_this());
    socket_.async_read_some(boost::asio::buffer(data_, 32),
                            [this, self](boost::system::error_code ec, std::size_t len) {
        if (!ec)
        {
            for(int i = 0; i < 32; i++)
            {
                std::cout<<data_[i];
            }
            //requestParser.do()
            write();
        }
        
    });
}


void Connection::write()
{
    auto self(shared_from_this());
    boost::asio::async_write(socket_, boost::asio::buffer(data_, 32), [this, self](boost::system::error_code ec, std::size_t){
        if(!ec)
            read();
    });
}