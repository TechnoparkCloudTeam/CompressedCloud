#include <boost/asio.hpp>
#include "IClientNetwork.h"

class ClientNetwork : public IClientNetwork {
public:
    void sendJson(std::string json) override;
    
    std::string getJson() override;
    
    void connect() override;
    
    void disconnect() override;

private:
    //для socketa нет конструктора по умолчанию
    //boost::asio::ip::tcp::socket connectSocket;

};