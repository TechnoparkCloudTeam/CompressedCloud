#pragma once

#include <boost/asio.hpp>
#include "ISession.h"
#include "Message.h"
#include "../../queue/include/queue.h"
namespace connection
{
    template <typename T>
    class Session : public ISession
    {
    public:
        Session();
        
        ~Session();
        
        void connect() override;
        
        void disconnect() override;
        
        void isConnect() const override;
        
        void send(const msg::Message<T> msg);
    
    
    private:
        boost::asio::ip::tcp::socket socket_;

        boost::asio::io_context io_context_;

        q::Queue<msg::Message<T>> qOut; //должны быть указатель на интерфейс очереди, пока так
        
        q::Queue<msg::Message<T>>& qIn;
    };
}