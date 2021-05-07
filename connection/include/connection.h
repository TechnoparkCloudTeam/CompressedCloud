#include <boost/asio.hpp>
#include <array>
#include <string>
struct RequestParser{

};

class Connection : public std::enable_shared_from_this<Connection>
{
public:
    explicit Connection(boost::asio::ip::tcp::socket socket_);
    
    void start();

    void stop();



private:
    void read();

    void write();

    boost::asio::ip::tcp::socket socket_;

    RequestParser requestParser;

    //std::array<char, 8192> buffer_In;
    char data_[24];

};