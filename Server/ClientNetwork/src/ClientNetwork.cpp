#include "../include/ClientNetwork.h"
#include <string_view>
#include <fstream>
#define header_size 4
enum ServerSynchoRead
{
    OKREG = 0,
    REGISTRATION = 1,
    AUTORIZATION = 2,
    OKLOGIN = 3,
    BADLOGIN = 4
};

enum ServerFSWrite
{
    CREATEFOLDER = 1,
};

unsigned decode_header(std::vector<boost::uint8_t> &buf)
{
    unsigned msg_size = 0;
    for (unsigned i = 0; i < header_size; ++i)
        msg_size = msg_size * 256 + (static_cast<unsigned>(buf[i]) & 0xFF);
    return msg_size;
}

std::string encode_header(std::vector<boost::uint8_t> &buf, unsigned size)
{
    buf[0] = static_cast<boost::uint8_t>((size >> 24) & 0xFF);
    buf[1] = static_cast<boost::uint8_t>((size >> 16) & 0xFF);
    buf[2] = static_cast<boost::uint8_t>((size >> 8) & 0xFF);
    buf[3] = static_cast<boost::uint8_t>(size & 0xFF);
    std::string sizeStr(buf.begin(), buf.end());
    return sizeStr;
}
ClientNetwork::ClientNetwork(boost::asio::io_service &io_service) : socket_(io_service),
                                                                    socketS_(io_service),
                                                                    socketToSynch(io_service),
                                                                    io_service_(io_service)
{

    boost::asio::ip::tcp::endpoint eps(boost::asio::ip::address::from_string("127.0.0.1"), 6666);
    socketS_.async_connect(eps, boost::bind(&ClientNetwork::handleConnectS, this,
                                            boost::asio::placeholders::error));

    boost::asio::ip::tcp::endpoint ep(boost::asio::ip::address::from_string("127.0.0.1"), 8888);
    socket_.async_connect(ep, boost::bind(&ClientNetwork::handleConnectFS, this,
                                          boost::asio::placeholders::error));
}
void ClientNetwork::handleConnectFS(boost::system::error_code ec)
{
    start_read_header_fs();
}
void ClientNetwork::start_read_header_fs()
{
    m_readbuf_fs.resize(header_size);
    boost::asio::async_read(socket_, boost::asio::buffer(m_readbuf_fs),
                            boost::bind(&ClientNetwork::handle_read_header_fs, this));
}

void ClientNetwork::handle_read_header_fs()
{
    unsigned msg_len = decode_header(m_readbuf_fs);
    std::cout << "MSG LEN: " << msg_len << std::endl;
    start_read_body_fs(msg_len);
}

void ClientNetwork::start_read_body_fs(unsigned msg_len)
{
    m_readbuf_fs.resize(header_size + msg_len);
    boost::asio::mutable_buffers_1 buf = boost::asio::buffer(&m_readbuf_fs[header_size], msg_len);
    boost::asio::async_read(socket_, buf, boost::bind(&ClientNetwork::handle_read_body_fs, this));
}
void ClientNetwork::handle_read_body_fs()
{
    
    messageFS::Request readed;
    readed.ParseFromArray(&m_readbuf_fs[header_size], m_readbuf_fs.size() - header_size);
    std::cout << "\n\nreaded: " << readed.id() << "\n\n";
    switch (readed.id())
    {
    case 1:
    {
        std::ofstream( "SynchFolder/" + readed.filename(), std::ios_base::binary) << readed.file().c_str();
        break;
    }
    default:
        break;
    }
    start_read_header_fs();
}

void ClientNetwork::writeMessageToFS(boost::system::error_code ec, const std::string &msg)
{
    io_service_.post(boost::bind(&ClientNetwork::doWriteFS, this, msg));
}
void ClientNetwork::doWriteFS(std::string &msg)
{
    std::vector<boost::uint8_t> buf(4);
    std::string size = encode_header(buf, msg.size());

    msg = size + msg;
    bool write_in_progress = !qWrite.empty();

    qWrite.push_back(msg);
    if (!write_in_progress)
    {
        boost::asio::async_write(socket_, boost::asio::buffer(qWrite.front().data(), qWrite.front().length()),
                                 boost::bind(&ClientNetwork::writeHeandlerFS, this));
    }
}

void ClientNetwork::writeHeandlerFS()
{
    qWrite.pop_front();
    if (!qWrite.empty())
    {
        boost::asio::async_write(socket_, boost::asio::buffer(qWrite.front().data(), qWrite.front().length()),
                                 boost::bind(&ClientNetwork::writeHeandlerS, this));
    }
}


//-------------------------------------------------------------------------------------------
void ClientNetwork::handleConnectS(boost::system::error_code ec)
{
    start_read_header_s();
}

void ClientNetwork::start_read_header_s()
{
    m_readbuf_s.resize(header_size);
    boost::asio::async_read(socketS_, boost::asio::buffer(m_readbuf_s),
                            boost::bind(&ClientNetwork::handle_read_header_s, this));
}

void ClientNetwork::handle_read_header_s()
{
    unsigned msg_len = decode_header(m_readbuf_s);
    std::cout << "MSG LEN: " << msg_len << std::endl;
    start_read_body_s(msg_len);
}

void ClientNetwork::start_read_body_s(unsigned msg_len)
{
    m_readbuf_s.resize(header_size + msg_len);
    boost::asio::mutable_buffers_1 buf = boost::asio::buffer(&m_readbuf_s[header_size], msg_len);
    boost::asio::async_read(socketS_, buf, boost::bind(&ClientNetwork::handle_read_body_s, this));
}

void ClientNetwork::handle_read_body_s()
{
    boost::system::error_code ec;

    messageFS::Request readed;
    readed.ParseFromArray(&m_readbuf_s[header_size], m_readbuf_s.size() - header_size);
    std::cout << "Readed from s id: " << readed.id() << " name: " << readed.name() << std::endl;
    switch (readed.id())
    {
    case ServerSynchoRead::OKREG:
    {
        readed.set_id(ServerFSWrite::CREATEFOLDER);
        std::string answer;
        readed.SerializePartialToString(&answer);
        writeMessageToFS(ec, answer);
    }
    break;
    case ServerSynchoRead::OKLOGIN:
        this->IsLogged = true;
        std::cout << "Logged in\n";
        break;
    case ServerSynchoRead::BADLOGIN:
        std::cout << "Bad login try again\n";
        break;
    default:
        break;
    }
    start_read_header_s();
}


void ClientNetwork::writeMessageToS(boost::system::error_code ec, const std::string &msg)
{
    io_service_.post(boost::bind(&ClientNetwork::doWriteS, this, msg));
}

void ClientNetwork::doWriteS(std::string &msg)
{
    std::vector<boost::uint8_t> buf(4);
    std::string size = encode_header(buf, msg.size());

    msg = size + msg;
    bool write_in_progress = !qWriteS.empty();

    qWriteS.push_back(msg);
    if (!write_in_progress)
    {
        boost::asio::async_write(socketS_, boost::asio::buffer(qWriteS.front().data(), qWriteS.front().length()),
                                 boost::bind(&ClientNetwork::writeHeandlerS, this));
    }
}

void ClientNetwork::writeHeandlerS()
{
    qWriteS.pop_front();
    if (!qWriteS.empty())
    {
        boost::asio::async_write(socketS_, boost::asio::buffer(qWriteS.front().data(), qWriteS.front().length()),
                                 boost::bind(&ClientNetwork::writeHeandlerS, this));
    }
}

bool ClientNetwork::IsLogin()
{
    return IsLogged;
}