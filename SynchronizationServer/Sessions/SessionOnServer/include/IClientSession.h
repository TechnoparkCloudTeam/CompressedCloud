#include <string>

class IClientSession {
public:
    virtual void connect() = 0;
  
    virtual void disconnect() = 0;
  
    virtual std::string getRequestFromClient() = 0;
  
    virtual void sendAnswerToClient(std::string) = 0;

    virtual int getClientId() const = 0;
};