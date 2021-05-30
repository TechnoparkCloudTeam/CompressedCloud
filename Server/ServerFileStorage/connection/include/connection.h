#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <string>
#include <thread>

#include "FileStorageWorker.h"
#include "RequestStatus.h"
#include "CodeHeader.h"
#include "message.pb.h"

class Connection : public std::enable_shared_from_this<Connection>
{
public:
    explicit Connection(boost::asio::ip::tcp::socket socket_);

    void start();

    void stop();

private:
    void start_read_header();

    void handle_read_header();

    void start_read_body(unsigned msg_len);

    void handle_read_body();

    void write(std::string &msg);

    boost::asio::ip::tcp::socket socket_;

    std::vector<uint8_t> m_readbuf;

    FileStorageWorker fsworker = FileStorageWorker("/home/lyalyashechka/filestorageDirectorie");

    CodeHeader headerMenager;
};