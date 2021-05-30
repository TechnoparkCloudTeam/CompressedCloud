#include "RequestCoordinator.h"

int RequestCoordinator::waitCancelDownload()
{
    int i = 0;
    while(Q.empty())
    {
        i++;
    }
    Q.pop();
    return 1;
}

void RequestCoordinator::add()
{
    Q.push(1);
}
