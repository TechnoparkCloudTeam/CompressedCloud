#include <boost/asio.hpp>
#include "IClientSession.h"

class ClientSession : public IClientSession {
public:

    void connect() override;
   
    void disconnect() override;
   
    std::string getRequestFromClient() override;
   
    void sendAnswerToClient(std::string json) override;

    int getClientId() const override;

private: 
    //для socketa нет конструктора по умолчанию
    //boost::asio::ip::tcp::socket connectSocket; 

    unsigned int clientId;
};


