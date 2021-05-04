#pragma once
#include <boost/asio.hpp>
#include <memory>
#include <thread>
#include <string>
#include "../../../message/include/Session.h"
namespace connection
{
    template <typename T>
    class ClientNetwork
    { //по сути является интерфейсом для сессии на стороне клиента
    public:
        ClientNetwork() : socket_(io_contex_){};

        ~ClientNetwork() { disconnect(); }

        void connect(const std::string &host, const int &port){
            connection_ = std::make_unique<Session<T>>();
        }

        void disconnect();

        bool isConnect() const;

    private:
        boost::asio::io_context io_contex_;

        boost::asio::ip::tcp::socket socket_;

        std::thread cnct_;

        q::Queue<msg::Message<T>> qIn;

        std::unique_ptr<Session<T>> connection_;
    };
}