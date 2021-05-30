#include <iostream>
#include "connection.h"

Connection::Connection(boost::asio::ip::tcp::socket socket_) : socket_(std::move(socket_))
{
}

void Connection::stop()
{
    socket_.close();
}

void Connection::start()
{
    startReadHeader();
}
void Connection::startReadHeader()
{
    m_readbuf.resize(header_size);
    boost::asio::async_read(socket_, boost::asio::buffer(m_readbuf),
                            boost::bind(&Connection::handleReadHeader, shared_from_this()));
}

void Connection::handleReadHeader()
{
    unsigned msg_len = headerMenager.decodeHeader(m_readbuf);
    std::cout << "MSG LEN: " << msg_len << std::endl;
    startReadBody(msg_len);
}
void Connection::startReadBody(unsigned msg_len)
{
    m_readbuf.resize(header_size + msg_len);
    boost::asio::mutable_buffers_1 buf = boost::asio::buffer(&m_readbuf[header_size], msg_len);
    boost::asio::async_read(socket_, buf, boost::bind(&Connection::handleReadBody, shared_from_this()));
}
void Connection::handleReadBody()
{
    messageFS::Request writeRequest;
    messageFS::Request readed;
    readed.ParseFromArray(&m_readbuf[header_size], m_readbuf.size() - header_size);
    writeRequest.set_name(readed.name());
    std::cout << readed.id() << " " << readed.name() << std::endl;
    switch (readed.id())
    {
    case ServerFS::CREATEFOLDER:
        std::cout << "Creating folder for user: " << readed.name() << std::endl;
        fsworker.createDirectory(readed.name());
        break;
    case ServerFS::DELETEFILE:
        std::cout << "Deleted file from user: " << readed.name() << std::endl;
        fsworker.removeFileFromDir(readed.name(), readed.filename());
        writeRequest.set_id(ServerFS::OKDELETE);
        writeRequest.set_name(readed.name());
        writeRequest.set_filename(readed.filename());
        break;
    case ServerFS::SENDFILE:
        std::cout << "Got file:" << readed.filename() << " from user: " << readed.name() << std::endl;
        fsworker.createFile(readed.name(), readed.filename(), readed.file().data(), readed.filesize());
        writeRequest.set_filesize(readed.filesize());
        writeRequest.set_filename(readed.filename());
        writeRequest.set_filepath(readed.filepath());
        writeRequest.set_fileextention(readed.fileextention());
        writeRequest.set_id(ServerFS::OKSENDING);
        break;
    case ServerFS::DOWNLOADFILE:
    {
        
        std::cout << "Sending file: " << readed.filename() << " to user: " << readed.name() << std::endl;
        std::string buffer = fsworker.fileToString(readed.name(), readed.filename());
        writeRequest.set_filename(readed.filename());
        writeRequest.set_file(buffer);
        writeRequest.set_id(ServerFS::OKDOWNLOAD);
        writeRequest.set_filesize(buffer.size());
        writeRequest.set_name(readed.name());
        break;
    }
    case ServerFS::DOWNLOADFILRFRIEND:
    {
        std::cout << "Sending file: " << readed.filename() << " to user: " << readed.name() << std::endl;
        std::string buffer = fsworker.fileToString(readed.loginfriend(), readed.filename());
        writeRequest.set_filename(readed.filename());
        writeRequest.set_file(buffer);
        writeRequest.set_id(ServerFS::OKDOWNLOAD);
        writeRequest.set_filesize(buffer.size());
        writeRequest.set_name(readed.name());
        break;
    }
    default:
        break;
    }

    std::string ans_string;
    writeRequest.SerializePartialToString(&ans_string);
    write(ans_string);
    startReadHeader();
}
void Connection::write(std::string &msg)
{
    std::vector<boost::uint8_t> buf(4);
    std::string size = headerMenager.encodeHeader(buf, msg.size());
    msg = size + msg;
    std::cout << "writing" << std::endl;
    boost::asio::write(socket_, boost::asio::buffer(msg));
}
