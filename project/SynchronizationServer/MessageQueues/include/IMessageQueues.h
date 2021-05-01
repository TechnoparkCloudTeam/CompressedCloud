#include <string>

class IMessageQueues {
public:
    virtual void putInQUeue(int, std::string) = 0;

    virtual void getRequestsFromClients() = 0;

    virtual void queueForSyncroIsEmpty() = 0;

    virtual std::string transferRequestToSyncro() = 0; 

};