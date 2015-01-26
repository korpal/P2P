#include "../../include/utils/EventQueue.hpp"
#include "../../include/controller/Events.hpp"

EventQueue& EventQueue::getInstance()
{
    static EventQueue eventQueue;
    return eventQueue;
}

EventQueue::EventQueue() {}

EventQueue::EventQueue(const EventQueue&) {}

void EventQueue::push(Event* const &item)
{
    std::unique_lock<std::mutex> mlock(mutex);
    queue.push(item);
    mlock.unlock();
    condition.notify_one();
}

Event* EventQueue::pop()
{
    std::unique_lock<std::mutex> mlock(mutex);
    while (queue.empty())
    {
        condition.wait(mlock);
    }
    auto item = queue.front();
    queue.pop();
    return item;
}