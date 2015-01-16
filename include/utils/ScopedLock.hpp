/**
 * Projekt z przedmiotu TIN - Program obsługujący prosty protokół P2P
 * Aleksander Bielawski
 * Rafał Witowski
 */

#ifndef SCOPED_LOCK_HPP
#define SCOPED_LOCK_HPP

#include <boost/noncopyable.hpp>
#include "Lock.hpp"
#include <iostream>

class ScopedLock : public boost::noncopyable
{
    public:
        ScopedLock(Lock &lock) : lock_(lock)
        {
            lock_.lock();
        }

        ~ScopedLock()
        {
            lock_.unlock();
        }

    private:
        Lock &lock_;
};

#endif
