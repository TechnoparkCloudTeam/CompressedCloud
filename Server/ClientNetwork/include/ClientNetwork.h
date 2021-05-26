#pragma once
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
#include <vector>
#include <thread>
#include "../../config.h"
class ClientNetwork 
{
public:
    ClientNetwork(boost::asio::io_service &io_service);

    void writeMessageToFS(const std::string &msg);

    void writeMessageToS(const std::string &msg);

    bool IsLogin();

    bool IsRegister();

    void SetIsRegisterToFalse();

private:
    void handleConnectFS(boost::system::error_code ec);

    void handleConnectS(boost::system::error_code ec);

    void doWriteFS(std::string &msg);

    void doWriteS(std::string &msg);

    void writeHeandlerFS();

    void writeHeandlerS();

    void start_read_header_s();

    void handle_read_header_s();

    void start_read_body_s(unsigned msg_len);

    void handle_read_body_s();

    void start_read_header_fs();

    void handle_read_header_fs();

    void start_read_body_fs(unsigned msg_len);

    void handle_read_body_fs();

    boost::asio::io_service &io_service_;

    boost::asio::ip::tcp::socket socket_;

    boost::asio::ip::tcp::socket socketS_;

    std::deque<std::string> qWrite;

    std::deque<std::string> qWriteS;

    std::vector<uint8_t> m_readbuf_s;

    std::vector<uint8_t> m_readbuf_fs;

    bool IsLogged = false;

    bool IsRegisted = false;

};