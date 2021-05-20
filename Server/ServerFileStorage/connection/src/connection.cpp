#include <iostream>
#include "../include/connection.h"
#define header_size 4

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
Connection::Connection(boost::asio::ip::tcp::socket socket_) : socket_(std::move(socket_))
{
}

void Connection::stop()
{
    socket_.close();
}

void Connection::start()
{
    start_read_header();
}
void Connection::start_read_header()
{
    m_readbuf.resize(header_size);
    boost::asio::async_read(socket_, boost::asio::buffer(m_readbuf),
                            boost::bind(&Connection::handle_read_header, shared_from_this()));
}

void Connection::handle_read_header()
{
    unsigned msg_len = decode_header(m_readbuf);
    std::cout << "MSG LEN: " << msg_len << std::endl;
    start_read_body(msg_len);
}
void Connection::start_read_body(unsigned msg_len)
{
    m_readbuf.resize(header_size + msg_len);
    boost::asio::mutable_buffers_1 buf = boost::asio::buffer(&m_readbuf[header_size], msg_len);
    boost::asio::async_read(socket_, buf, boost::bind(&Connection::handle_read_body, shared_from_this()));
}
void Connection::handle_read_body()
{
    //это в отдельный класс
    messageFS::Request writeRequest;
    messageFS::Request readed;
    readed.ParseFromArray(&m_readbuf[header_size], m_readbuf.size() - header_size);
    writeRequest.set_name(readed.name());
    std::cout << readed.id() << " " << readed.name() << std::endl;
    //на это ивенты
    switch (readed.id())
    {
    case 1:
        std::cout << "Creating folder for user: " << readed.name() << std::endl;
        fsworker.createDirectory(readed.name());
        break;
    case 2:
        std::cout << "Deleted file from user: " << readed.name() << std::endl;
        fsworker.removeFileFromDir(readed.name(), "file.txt");
    case 3:
        std::cout << "Got file from user: " << readed.name() << std::endl;
        fsworker.createFile(readed.name(), "test.txt", readed.file().c_str());
    default:
        break;
    }

    std::string ans_string;
    writeRequest.SerializePartialToString(&ans_string);
    write(ans_string);
    start_read_header();

    /* messageFS::Request ans;
    ans.set_id(1);
    std::string ans_string;
    ans.SerializePartialToString(&ans_string);
    boost::asio::async_write(socket_, boost::asio::buffer(ans_string, 250), boost::bind(&Connection::write, shared_from_this()));
*/
}
void Connection::write(std::string &msg)
{
    std::vector<boost::uint8_t> buf(4);
    std::string size = encode_header(buf, msg.size());
    msg = size + msg;
    std::cout << "writing" << std::endl;
    boost::asio::write(socket_, boost::asio::buffer(msg));
}
/*
void Connection::start()
{
    read();
}



*/