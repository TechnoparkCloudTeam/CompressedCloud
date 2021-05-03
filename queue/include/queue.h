#include <queue>
#include <mutex>
#include "IQueue.h"

namespace q
{

    template <typename T>
    class Queue : public IQueue
    {
    public:
        ~Queue()
        {
            clear();
        }

        void push(const T &item) override
        {
            std::scoped_lock lock(lockQ);
            q.push(item);
        }

        const T &pop() override
        {
            std::scoped_lock lock(lockQ);
            const T &item = q.front();
            q.pop();
            return item;
        }

        bool isEmpty() const override
        {
            return q.empty();
        }

        //можно удаления определенных запросов из очереди
    private:
        void clear()
        {
            std::scoped_lock lock(lockQ);
            q.clear();
        }

        std::mutex lockQ;
        std::queue<T> q;
    };

}