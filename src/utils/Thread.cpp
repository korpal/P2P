#include <cassert>

#include "../../include/utils/ScopedLock.hpp"
#include "../../include/utils/Thread.hpp"


Thread::Thread()
: finished_(false)
{}

Thread::~Thread()
{
    stop();
}

void Thread::start()
{
    assert(not isFinished());
    pthread_create(&thread_, NULL, &runWrapper, static_cast<void*>(this));
}

void Thread::join()
{
   pthread_join(thread_, NULL);
}

void Thread::stop()
{
    finish();
}

bool Thread::isFinished() const
{
    ScopedLock lock(lock_);
    return finished_;
}

void Thread::finish()
{
    lock_.lock();
    finished_ = true;
    lock_.unlock();
}

void* Thread::runWrapper(void* const thread)
{
    Thread& toRun(*static_cast<Thread*>(thread));
    toRun.run();
    toRun.finish();
    return NULL;
}

