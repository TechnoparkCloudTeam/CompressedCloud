#include "RequestCoordinator.h"

int RequestCoordinator::wait()
{
    while(Q.empty())
    {
    }
    Q.pop();
    return 1;
}

void RequestCoordinator::add()
{
    Q.push(1);
}
