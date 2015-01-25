#ifndef LOCK_HPP
#define LOCK_HPP

#include <pthread.h>

class Lock
{
public:
	Lock()
	{
        pthread_mutex_init(&lock_, NULL);
	}

	~Lock()
	{
		pthread_mutex_destroy(&lock_);
	}

	void lock()
	{
		pthread_mutex_lock(&lock_);
	}

	void unlock()
	{
		pthread_mutex_unlock(&lock_);
	}
	
	pthread_mutex_t& getMutex()
	{
	    return lock_;
	} 
private:
	pthread_mutex_t lock_;
};

#endif
