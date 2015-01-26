#ifndef BROADCASTSENDER_HPP
#define BROADCASTSENDER_HPP

#include "../utils/Thread.hpp"
#include "protocol/broadcast/BroadcastMessage.hpp"
#include "../resourcemanager/ResourceIdentifier.hpp"


class BroadcastSender : public Thread {
    public:
        BroadcastSender();
        virtual ~BroadcastSender();

        void requestAllResources();
        void requestResource(ResourceIdentifier &ri);
        void requestRevoke(ResourceIdentifier &ri);

    private:
        int sock;

        virtual void run();

        int createSocket();
};

#endif