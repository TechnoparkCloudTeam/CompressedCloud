#include "ClientNetwork.h"
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include "message.pb.h"
#include <fstream>
#include <boost/thread.hpp>
int main()
{
    messageFS::Request req;

    req.set_name("M.U.Lermontov");
    req.set_id(1);
    
    std::ifstream file("/home/lyalyashechka/TP/c_c++/gtiMAIN/CompressedCloud/project/ServerFileStorage/Client/test.txt", std::ios_base::binary);

    std::string file_string;
    file>>file_string;
    
    //req.set_file(file_string.c_str());

    std::string msg;
    req.SerializePartialToString(&msg);
    //вместо строки в врайт залетает протобаф.
    boost::asio::io_service io_service;
    ClientNetwork cn(io_service);
    boost::asio::ip::tcp::endpoint ep (boost::asio::ip::address::from_string("127.0.0.1"), 8888);
    boost::system::error_code ec;
    
boost::thread t(boost::bind(&boost::asio::io_service::run, &io_service));
    cn.writeMessageToFS(ec, msg);
    


        

    t.join();
}