#ifndef SENDER_HPP
#define SENDER_HPP

#include "../utils/Thread.hpp"
#include "../utils/SynchronizedQueue.hpp"
#include "Message.hpp"
#include "BroadcastMessage.hpp"
#include "UnicastMessage.hpp"


class Sender : public Thread {
    public:
        Sender(SynchronizedQueue<Message*> *squeue);
        virtual ~Sender();

        void sendBroadcast(BroadcastMessage *msg);
        void sendUnicast(UnicastMessage *msg);

    private:
        int sockBC;
        int sockUC;
        SynchronizedQueue<Message*> *squeue;

        virtual void run();

        int createBroadcastSocket();
        int createLocalHostSocket();
};

#endif
