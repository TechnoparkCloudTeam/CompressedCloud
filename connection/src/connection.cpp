#include <iostream>
#include "connection.h"

Connection::Connection(boost::asio::ip::tcp::socket socket_) : socket_(std::move(socket_))
{
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
    boost::asio::async_read(
        socket_,
        boost::asio::buffer(data_),
        boost::asio::transfer_at_least(1),
        boost::bind(&Connection::handleRead, shared_from_this()));
}

void Connection::handleRead()
{
        google::protobuf::io::ArrayInputStream arrayInputStream(data_,5000);
        google::protobuf::io::CodedInputStream codedInputStream(&arrayInputStream);
        uint32_t messageSize;
        codedInputStream.ReadVarint32(&messageSize);

        messageFS::Request req;
        
        req.ParseFromCodedStream(&codedInputStream);

        std::cout<<req.id()<<" "<<req.name()<<std::endl;

        if (req.id() == 4)
            std::cout<<"Creating folder for user: "<<req.name()<<std::endl;

        if (req.id() == 1)
            std::cout<<"Getting file from user: "<<req.name()<<std::endl;

        if(req.id() == 2)
            std::cout<<"Sending file to user: "<<req.name()<<std::endl;
        read();
}

void Connection::write()
{
    auto self(shared_from_this());
    boost::asio::async_write(socket_, boost::asio::buffer(data_, 128), [this, self](boost::system::error_code ec, std::size_t) {
        if (!ec)
            read();
    });
}