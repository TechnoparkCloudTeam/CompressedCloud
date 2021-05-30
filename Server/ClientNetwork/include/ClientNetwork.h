#pragma once

#include <string>
#include <iostream>
#include <deque>
#include <vector>
#include <thread>
#include <string_view>
#include <fstream>
#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include "boost/log/trivial.hpp"
#include <boost/lexical_cast.hpp>

#include "RequestStatus.h"
#include "CodeHeader.h"
#include "PatternWatcher.h"

#include "message.pb.h"

class ClientNetwork 
{
public:
    ClientNetwork(boost::asio::io_service &io_service, std::shared_ptr<PatternWatcher> PWPtr_);

    void writeMessageToFS(const std::string &msg);

    void writeMessageToS(const std::string &msg);

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

    std::shared_ptr<PatternWatcher> PWPtr;

    CodeHeader headerMenager;
};