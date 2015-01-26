#ifndef BROADCASTSENDER_HPP
#define BROADCASTSENDER_HPP

#include "../utils/Thread.hpp"
#include "protocol/broadcast/BroadcastMessage.hpp"
#include "../resourcemanager/ResourceIdentifier.hpp"


class BroadcastSender : public Thread {
    public:
        static BroadcastSender& getInstance();
        virtual ~BroadcastSender();

        void requestAllResources();
        void requestResource(ResourceIdentifier &ri);
        void requestRevoke(ResourceIdentifier &ri);
        void requestRevert(ResourceIdentifier &ri);

    private:
        BroadcastSender();
        BroadcastSender(const BroadcastSender&);
        virtual void run();

        int sock;
        int createSocket();
};

#endif