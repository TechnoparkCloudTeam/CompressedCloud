#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include "message.pb.h"

int main()
{
    messageFS::Request req;

    req.set_name("M.U.Lermontov");
    req.set_id(1);
    boost::asio::io_service io_service_;
    boost::asio::ip::tcp::resolver resolver(io_service_);
    boost::asio::ip::tcp::resolver::results_type endpoints =
        resolver.resolve({"127.0.0.1", "8888"});

    boost::asio::ip::tcp::socket socket_(io_service_);
    boost::asio::connect(socket_, endpoints);

    std::string str;
    req.SerializePartialToString(&str);
    

    boost::system::error_code error;

    boost::array<char, 128> bufIn;

    socket_.write_some(boost::asio::buffer(str), error);
    socket_.read_some(boost::asio::buffer(bufIn), error);
    
    /* socket_.write_some(streamBuffer_.data(), error); 
     */

      for (int i = 0; i < 100; i++)
        std::cout << bufIn[i];  
}