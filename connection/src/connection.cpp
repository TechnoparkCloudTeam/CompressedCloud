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
    auto self(shared_from_this());
    socket_.async_read_some(boost::asio::buffer(data_),
            [this, self](boost::system::error_code ec, std::size_t length) {
            if (!ec)
            {
                //это в отдельный класс
                messageFS::Request req;
                req.ParseFromString(data_);
                std::cout<<req.id()<<" "<<req.name()<<" "<<req.file()<< std::endl; 
                //на это ивенты
                if (req.id() == 1)
                {
                    std::cout << "Creating folder for user: " << req.name() << std::endl;
                    fsworker.createDirectory(req.name());
                    write();
                }
                if (req.id() == 2)
                {
                    std::cout<<"Deleted file from user: "<<req.name()<<std::endl;
                    fsworker.removeFileFromDir(req.name(), "file.txt");
                   
                }
                if (req.id() == 3)
                {
                    std::cout<<"Got file from user: "<<req.name()<<std::endl;
                    fsworker.createFile(req.name(), "test.txt", req.file().c_str());
                }
                write();
            }
        });
}


void Connection::write()
{
    auto self(shared_from_this());
    boost::asio::async_write(socket_, boost::asio::buffer(data_, 8192), [this, self](boost::system::error_code ec, std::size_t) {
        if (!ec)
            read();
    });
}