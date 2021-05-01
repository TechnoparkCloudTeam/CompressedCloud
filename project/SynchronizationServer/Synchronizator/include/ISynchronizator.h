#include <string>

class ISyncronizator {
public: 
    virtual void sendRequestToDB (std::string) = 0;
    
    virtual std::string getAnswerFromDB () = 0;
};