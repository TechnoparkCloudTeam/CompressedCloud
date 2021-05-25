#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <array>
#include <string>
#include <vector>
#include "PostgreSQLDB.h"
#include "MetaDB.h"
#include "FriendDB.h"
#include "../../../../DataBases/PostgresDB/UserDB/include/UserDB.h"

#include "../../../../DataBases/PostgresDB/UserDB/include/UserInfo.h"
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

    /* void read(); */

    void write(std::string &msg);

/*     void handleRead();
 */
    boost::asio::ip::tcp::socket socket_;

    char data_[8192];
    std::vector<uint8_t> m_readbuf;
    std::shared_ptr<UsersDB> postgres_sqldb1;
    std::shared_ptr<MetaDataDB> postgres_sqldb_file;
    std::shared_ptr<FriendDB> postgres_sqldb_friends;
};