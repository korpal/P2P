#ifndef TIMED_BLOCKING_QUEUE
#define TIMED_BLOCKING_QUEUE

#include <sys/wait.h>
#include <list>

template <typename T>
class TimedBlockingQueue
{
public:
    TimedBlockingQueue ();
    ~TimedBlockingQueue ();
    bool push(const T& data);
    T pop(const int seconds);
private:
    std::list<T> _list;
    pthread_mutex_t _lock;
    pthread_cond_t _cond;
};

#endif