#include <memory>
#include "ISynchronizator.h"
#include "IMessageQueues.h"
class Syncronizator : public ISyncronizator {
public:
    void sendRequestToDB(std::string) override;
    
    std::string getAnswerFromDB() override;

private:
    std::string getFromQueue();

    void putToQueue(std::string, int id);

    std::shared_ptr <IMessageQueues> MessageQueues;

    //std::shared_ptr <Command> Command;

};