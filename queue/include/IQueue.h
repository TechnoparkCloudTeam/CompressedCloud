namespace q
{
    template <typename T>
    class IQueue
    {
    public:
        virtual void push(const T &item) = 0;
        virtual void pop(const T &item) = 0;
        virtual bool isEmpty() const = 0;
        virtual ~IQueue() = 0;
    };
}