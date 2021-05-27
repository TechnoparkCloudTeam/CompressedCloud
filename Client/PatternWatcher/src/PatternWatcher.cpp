#include "PatternWatcher.h"

int PatternWatcher::waitCancelDownload()
{
    int i = 0;
    while(Q.empty())
    {
        i++;
    }
    std::cout<<"\n\n\n" <<i<<" \n\n\n";
    Q.pop();
    std::cout<<"\n\n\nsize "<<Q.size()<<"\n\n\n";
    return 1;
}

void PatternWatcher::add()
{
        std::cout<<"\n\n\n 2 \n\n\n";

    Q.push(1);
}