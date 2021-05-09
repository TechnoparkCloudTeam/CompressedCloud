#include "ClientNetwork.h"

int main()
{

    //вместо строки в врайт залетает протобаф.
    boost::asio::io_service io_service;
    std::string msg = "hahaha";
    ClientNetwork cn(io_service);
    boost::asio::ip::tcp::endpoint ep (boost::asio::ip::address::from_string("127.0.0.1"), 8888);
    cn.start(ep, msg);
    io_service.run();
    boost::system::error_code ec;
    cn.writeMessage(ec, msg);
    
}