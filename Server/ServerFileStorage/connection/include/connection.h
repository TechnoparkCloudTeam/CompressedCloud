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
    void startReadHeader();

    void handleReadHeader(const boost::system::error_code &error);

    void startReadBody(unsigned msg_len);

    void handleReadBody(const boost::system::error_code &error);

    void write(std::string &msg);

    boost::asio::ip::tcp::socket socket_;

    std::vector<uint8_t> m_readbuf;

    FileStorageWorker fsworker = FileStorageWorker("/home/ilya/Techno");

    CodeHeader headerMenager;
};