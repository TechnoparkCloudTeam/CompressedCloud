#include "ClientNetwork.h"
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include "message.pb.h"
#include <fstream>
int main()
{
    messageFS::Request req;

    req.set_name("M.U.Lermontov");
    req.set_id(3);
    
    std::ifstream file("/home/lyalyashechka/TP/c_c++/gitMain/CompressedCloud/Client/test.txt", std::ios_base::binary);

    std::string file_string;
    file>>file_string;
    std::cout<<file_string.size()<<"                           dfsgfg";
    req.set_file(file_string.c_str());

    std::string msg;
    req.SerializePartialToString(&msg);
    //вместо строки в врайт залетает протобаф.
    boost::asio::io_service io_service;
    ClientNetwork cn(io_service);
    boost::asio::ip::tcp::endpoint ep (boost::asio::ip::address::from_string("127.0.0.1"), 8888);
    cn.start(ep, msg);
    io_service.run();
    boost::system::error_code ec;
    cn.writeMessage(ec, msg);
    
}