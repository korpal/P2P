#ifndef _QUEUE_
#define _QUEUE_

#include <iostream>
#include <mutex>

#include <queue>
#include <condition_variable>

using namespace std;
// Queue class that has thread synchronisation
template <typename T>
class SynchronizedQueue
{
private:
    std::queue<T> m_queue;            // Use STL queue to store data
    std::mutex m_mutex;            // The mutex to synchronise on
    std::condition_variable m_cond;    // The condition to wait for
    long m_size; // for help

public:

    SynchronizedQueue() : m_size(0) { }
    virtual ~SynchronizedQueue() throw () { }

    long Size()
    {
        return m_size;
    }

    // Add data to the queue and notify others
    void push(const T& data)
    {
        // Acquire lock on the queue
        std::unique_lock<std::mutex> lock(m_mutex);

        // Add the data to the queue
        m_queue.push(data);
        m_size++;

        // Notify others that data is ready
        m_cond.notify_one();

    } // Lock is automatically released here

    // Get data from the queue. Wait for data if not available
    T pop()
    {

        // Acquire lock on the queue
        std::unique_lock<std::mutex> lock(m_mutex);

        // When there is no data, wait till someone fills it.
        // Lock is automatically released in the wait and obtained
        // again after the wait
        while (m_queue.size()==0)
            m_cond.wait(lock);

        // Retrieve the data from the queue
        T result=m_queue.front();
        m_queue.pop();
        m_size--;
        return result;

    } // Lock is automatically released here
};
#endif
