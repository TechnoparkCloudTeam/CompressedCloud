#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include "message.pb.h"
#include <string>
#include <iostream>
#include <deque>
#define max_size_buf 100

class ClientNetwork : public boost::enable_shared_from_this<ClientNetwork>
{
public:
    ClientNetwork(boost::asio::io_service& io_service);

    void handleConnectFS(boost::system::error_code ec);

    void handleConnectS(boost::system::error_code ec);

    void writeMessageToFS(boost::system::error_code ec, const std::string& msg);

    void writeMessageToS(boost::system::error_code ec, const std::string& msg);

    void doWriteFS(const std::string &msg);

    void doWriteS(const std::string &msg);

    void writeHeandlerFS();

    void writeHeandlerS();

    void handleReadFS(boost::system::error_code ec);
    
    void handleReadS(boost::system::error_code ec);
private:

    boost::asio::io_service& io_service_;

    boost::asio::ip::tcp::socket socket_;

    boost::asio::ip::tcp::socket socketS_;

    boost::asio::ip::tcp::socket socketToSynch;
    
    std::string message_;

    char read_data[max_size_buf];

    char write_data[max_size_buf];

    std::deque<std::string> qWrite;

    std::deque<std::string> qWriteS;
};