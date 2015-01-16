/**
 * Projekt z przedmiotu TIN - Program obsługujący prosty protokół P2P
 * Aleksander Bielawski
 * Rafał Witowski
 */

#ifndef THREAD_HPP
#define THREAD_HPP

#include <pthread.h>

#include "Lock.hpp"

class Thread
{
public:
	Thread();
	virtual ~Thread();
	void start();
	void join();
	void stop();
	bool isFinished() const;
protected:
	virtual void run() = 0;
	void finish();
private:
	static void* runWrapper(void* thread);
	bool finished_;
	mutable Lock lock_;
	pthread_t thread_;
};

#endif
