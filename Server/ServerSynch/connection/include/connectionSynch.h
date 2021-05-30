#pragma once

#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <string>
#include <vector>

#include "PostgreSQLDB.h"
#include "MetaDB.h"
#include "FriendDB.h"
#include "UserDB.h"
#include "UserInfo.h"
#include "FileInfo.h"
#include "CodeHeader.h"
#include "RequestStatus.h"

#include "message.pb.h"

class Connection : public std::enable_shared_from_this<Connection>
{
public:
    explicit Connection(boost::asio::ip::tcp::socket socket_, std::shared_ptr<UsersDB> postgres_sqldb12,
                        std::shared_ptr<MetaDataDB> postgres_sqldb_file, std::shared_ptr<FriendDB> postgres_sqldb_friend);

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

    std::shared_ptr<UsersDB> postgres_sqldb1;

    std::shared_ptr<MetaDataDB> postgres_sqldb_file;

    std::shared_ptr<FriendDB> postgres_sqldb_friends;

    CodeHeader headerMenager;
};