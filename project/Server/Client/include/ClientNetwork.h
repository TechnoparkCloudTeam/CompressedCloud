#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <string>
#include <iostream>

#define max_size_buf 1024

class ClientNetwork 
{
public:
    ClientNetwork(boost::asio::io_service& io_service);

    void start(boost::asio::ip::tcp::endpoint ep, const std::string& message);

    void writeMessage(boost::system::error_code ec, const std::string& msg);

    void readMessage(boost::system::error_code ec);

    void handleRead(boost::system::error_code ec);
private:
    boost::asio::ip::tcp::socket socket_;

    boost::asio::ip::tcp::socket socketToSynch;
    
    std::string message_;

    char read_data[max_size_buf];

    char write_data[max_size_buf];
};