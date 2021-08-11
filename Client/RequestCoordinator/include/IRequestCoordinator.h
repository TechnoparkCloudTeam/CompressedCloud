struct IRequestCoordinator
{
    virtual int wait() = 0;
    
    virtual void add(const int& status) = 0;
};
