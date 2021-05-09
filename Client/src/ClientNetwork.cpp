#include "ClientNetwork.h"

ClientNetwork::ClientNetwork(boost::asio::io_service &io_service) :
                                             socket_(io_service),
                                             socketToSynch(io_service)
{
}

void ClientNetwork::start(boost::asio::ip::tcp::endpoint ep, const std::string &msg)
{
    socket_.async_connect(ep, boost::bind(&ClientNetwork::writeMessage, this,
                                          boost::asio::placeholders::error, msg));
     //клиент общается с 2 серверами
    /* boost::asio::ip::tcp::endpoint epS (boost::asio::ip::address::from_string("127.0.0.1"), 6666);
   
    socketToSynch.async_connect(epS, boost::bind(&ClientNetwork::writeMessage, this,
                                          boost::asio::placeholders::error, msg));    */                                 
}

void ClientNetwork::writeMessage(boost::system::error_code ec, const std::string &msg)
{
    std::copy(msg.begin(), msg.end(), write_data);
    boost::asio::async_write(socket_, boost::asio::buffer(write_data, max_size_buf),
                             boost::bind(&ClientNetwork::readMessage, this, boost::asio::placeholders::error));
}

void ClientNetwork::readMessage(boost::system::error_code ec)
{
    boost::asio::async_read(socket_, boost::asio::buffer(read_data, max_size_buf), boost::asio::transfer_at_least(1),
                            boost::bind(&ClientNetwork::handleRead, this, boost::asio::placeholders::error));
}

void ClientNetwork::handleRead(boost::system::error_code ec)
{
    //тут че то делается
    for(int i = 0; i < 100; i++)
        std::cout<<read_data[i];
}