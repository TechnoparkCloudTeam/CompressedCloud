#include "RequestCoordinator.h"

int RequestCoordinator::wait()
{
    while(Q.empty())
    {
    }
    int status = Q.back();
    Q.pop();
    return status;
}

void RequestCoordinator::add(const int& status)
{
    Q.push(status);
}
