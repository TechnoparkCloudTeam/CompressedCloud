#pragma once

#include <queue>
#include <mutex>
#include "IQueue.h"

namespace q
{

    template <typename T>
    class Queue 
    {
    public:
        ~Queue()
        {
            clear();
        }

        void push(const T &item) 
        {
            std::scoped_lock lock(lockQ);
            q.push(item);
        }

        const T &pop() 
        {
            std::scoped_lock lock(lockQ);
            const T &item = q.front();
            q.pop();
            return item;
        }

        bool isEmpty() const 
        {
            return q.empty();
        }

        //можно удаления определенных запросов из очереди
    private:
        void clear()
        {
            std::scoped_lock lock(lockQ);
            q = {};
        }

        std::mutex lockQ;
        std::queue<T> q;
    };

}