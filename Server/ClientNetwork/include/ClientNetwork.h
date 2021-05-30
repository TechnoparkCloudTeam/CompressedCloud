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
#include "RequestCoordinator.h"

#include "message.pb.h"

class ClientNetwork 
{
public:
    ClientNetwork(boost::asio::io_service &io_service, std::shared_ptr<RequestCoordinator> PWPtr_);

    void writeMessageToFS(const std::string &msg);

    void writeMessageToS(const std::string &msg);

private:
    void handleConnectFS(boost::system::error_code ec);

    void handleConnectS(boost::system::error_code ec);

    void doWriteFS(std::string &msg);

    void doWriteS(std::string &msg);

    void writeHeandlerFS();

    void writeHeandlerS();

    void startReadHeaderS();

    void handleReadHeaderS();

    void startReadBodyS(unsigned msg_len);

    void handleReadBodyS();

    void startReadHeaderFS();

    void handleReadHeaderFS();

    void startReadBodyFS(unsigned msg_len);

    void handleReadBodyFS();

    boost::asio::io_service &io_service_;

    boost::asio::ip::tcp::socket socket_;

    boost::asio::ip::tcp::socket socketS_;

    std::deque<std::string> qWrite;

    std::deque<std::string> qWriteS;

    std::vector<uint8_t> m_readbuf_s;

    std::vector<uint8_t> m_readbuf_fs;

    std::shared_ptr<RequestCoordinator> PWPtr;

    CodeHeader headerMenager;
};
