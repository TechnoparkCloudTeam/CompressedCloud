#include <queue>
#include <vector>
#include <memory>
#include "IMessageQueues.h"
#include "ClientSession.h"


class MessageQueues : public IMessageQueues{
public:
    void putInQUeue(int, std::string) override;

    void getRequestsFromClients() override;

    void queueForSyncroIsEmpty() override;

    std::string transferRequestToSyncro() override;

private:
    void createNewQueueForClient();

    void queueForClientIsExists(int);

    std::queue<std::pair<std::string, int>> queueForSyncro;
    
    std::vector<std::queue<std::pair<std::string, int>>> queueForClients; 

    std::shared_ptr <IClientSession> ClientsSession;

};