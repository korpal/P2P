#ifndef TIMED_BLOCKING_QUEUE
#define TIMED_BLOCKING_QUEUE

#include <sys/wait.h>
#include <list>

template <typename T>
class TimedBlockingQueue
{
public:
    TimedBlockingQueue () {}
    ~TimedBlockingQueue () {}

    void push(const T& data)
    {
        bool was_empty;
        pthread_mutex_lock(&_lock);
        was_empty = _list.empty();
        _list.push_back(data);
        pthread_mutex_unlock(&_lock);
        if (was_empty)
            pthread_cond_broadcast(&_cond);
    }

    T pop(const int seconds)
    {
        struct timespec ts1, ts2;
        clock_gettime(CLOCK_REALTIME, &ts1);
        pthread_mutex_lock(&_lock);
        clock_gettime(CLOCK_REALTIME, &ts2);
        int result = 0;
        // First Check
        if ((ts1.tv_sec - ts2.tv_sec) < seconds) {
            ts2.tv_sec += seconds; // specify wake up time
            while(_list.empty( ) && (result == 0)) {
                result = pthread_cond_timedwait(&_cond, &_lock, &ts2) ;
            }
            if (result == 0) { // Second Check
                T _temp = _list.front( );
                _list.pop_front( );
                pthread_mutex_unlock(&_lock);
                return _temp;
            }
        }
        pthread_mutex_unlock(&_lock);
        throw "timeout happened";
    }

private:
    std::list<T> _list;
    pthread_mutex_t _lock;
    pthread_cond_t _cond;
};

#endif