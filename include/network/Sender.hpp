#ifndef SENDER_HPP
#define SENDER_HPP

#include "../utils/Thread.hpp"
#include "../utils/SynchronizedQueue.hpp"
#include "protocol/broadcast/BroadcastMessage.hpp"


class Sender : public Thread {
    public:
        Sender(SynchronizedQueue<BroadcastMessage*> *squeue);
        virtual ~Sender();

        void sendBroadcast(BroadcastMessage *msg);
        //void sendUnicast(UnicastMessage *msg);

    private:
        int sockBC;
        int sockUC;
        SynchronizedQueue<BroadcastMessage*> *squeue;

        virtual void run();

        int createBroadcastSocket();
        int createLocalHostSocket();
};

#endif
