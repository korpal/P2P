#ifndef SENDER_HPP
#define SENDER_HPP

#include "../utils/Thread.hpp"
#include "../utils/SynchronisedQueue.hpp"
#include "Message.hpp"
#include "BroadcastMessage.hpp"
#include "UnicastMessage.hpp"


class Sender : public Thread {
    public:
        Sender(SynchronisedQueue<Message*> *squeue);
        virtual ~Sender();

        void sendBroadcast(BroadcastMessage *msg);
        void sendUnicast(UnicastMessage *msg);

    private:
        int sockBC;
        int sockUC;
        SynchronisedQueue<Message*> *squeue;

        virtual void run();

        int createBroadcastSocket();
        int createLocalHostSocket();
};

#endif
