#include <string>
class IClientNetwork {
public:
    virtual void sendJson(std::string) = 0;
    
    virtual std::string getJson() = 0;
    
    virtual void connect() = 0;
    
    virtual void disconnect() = 0;
};