#pragma once

#include <memory>
#include <boost/asio.hpp>
#include <thread>
#include <vector>
#include "Message.h"
#include "Session.h"
#include "queue.h"

namespace cloudserver
{
    template <typename T>
    class CloudServer
    {
    public:
        CloudServer(u_int16_t port) : acceptor_(io_contex_,
                                                boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(),
                                                                               port)){};

        ~CloudServer() { stop(); }

        void start()
        {

            waitForClientConnection();
            t_contex = std::thread([this]() { io_contex_.run(); });

            std::cout << "I,m running" << std::endl;
        }

        void stop()
        {
            io_contex_.stop();
            if (t_contex.joinable())
                t_contex.join();

            std::cout << "I'm stopted" << std::endl;
        }

        void waitForClientConnection()
        {
            acceptor_.async_accept([this](std::error_code er,
                                          boost::asio::ip::tcp::socket socket_) {
                if (!er)
                {
                    /* std::cout << "Connected to me " << socket_.remote_endpoint() << std::endl;
                    std::shared_ptr<connection::Session<T>> newconn =
                        std::make_shared<connection::Session<T>>(connection::Session<T>::owner::server,
                                                                 io_contex_, std::move(socket_), qIn); */
                    /* if (onClientConnect(newconn))
                    {
                        allConnection.push_back(std::move(newconn));
                    } */
                }
                waitForClientConnection();
            });
        }

        void messageToClient(std::shared_ptr<connection::Session<T>> client, const msg::Message<T> &msg)
        {
            if (client->isConnect())
            {
                client->send(msg);
            }
        }

        void update(size_t nMaxMessages = -1)
        {
            size_t nMessageCount = 0;
            while (nMessageCount < nMaxMessages && !qIn.isEmpty()){
                auto msg = qIn.pop();
                messageFromClient(msg.remote, msg.m);
                nMessageCount++;

            }
        }

    private:
        bool onClientConnect(std::shared_ptr<connection::Session<T>> client);

        void messageFromClient(std::shared_ptr<connection::Session<T>> client, msg::Message<T> &msg)
        {
            return;
        }

        std::vector<std::shared_ptr<connection::Session<T>>> allConnection;

        q::Queue<msg::MessageFromServer<T>> qIn;

        boost::asio::io_context io_contex_;

        std::thread t_contex;

        boost::asio::ip::tcp::acceptor acceptor_;

        
        //надо понять какому клиенту отвечать uint id???

        //std::unique_ptr<FileStorage> fs;
    };

}
