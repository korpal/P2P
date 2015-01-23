#ifndef BROADCASTSENDER_HPP
#define BROADCASTSENDER_HPP

#include "../utils/Thread.hpp"
#include "protocol/broadcast/BroadcastMessage.hpp"


class BroadcastSender : public Thread {
    public:
        BroadcastSender();
        virtual ~BroadcastSender();

        void requestAllResources();
        void requestResource(char *msg);
        void requestRevoke();

    private:
        int sock;

        virtual void run();

        int createSocket();
};

#endif