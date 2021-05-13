#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <array>
#include <string>
#include "FileStorageWorker.h"
#include "message.pb.h"

class Connection : public std::enable_shared_from_this<Connection>
{
public:
    explicit Connection(boost::asio::ip::tcp::socket socket_);
    
    void start();

    void stop();

private:
    void read();
    
    void write();

    void handleRead();

    boost::asio::ip::tcp::socket socket_;

    //std::array<char, 8192> buffer_In;
    char data_[8192];

    FileStorageWorker fsworker = FileStorageWorker("/home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/build/content");
};