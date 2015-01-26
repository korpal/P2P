#ifndef EVENT_QUEUE_H
#define EVENT_QUEUE_H

#include <queue>
#include <mutex>
#include <condition_variable>
#include "../controller/Events.hpp"


class EventQueue
{
private:
    EventQueue();
    EventQueue(const EventQueue&);
    static EventQueue eventQueue;

    std::queue<Event*> queue;
    std::mutex mutex;
    std::condition_variable condition;

public:

    void push(Event* const &item);

    Event* pop();

    static EventQueue& getInstance();
};

#endif
