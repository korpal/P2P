#ifndef BROADCASTRECEIVER_HPP
#define BROADCASTRECEIVER_HPP

#include "../utils/Thread.hpp"
#include "protocol/broadcast/BroadcastAllResources.hpp"
#include "protocol/broadcast/BroadcastResource.hpp"
#include "protocol/broadcast/BroadcastRevoke.hpp"


class BroadcastReceiver : public Thread {
    public:
        BroadcastReceiver();
        virtual ~BroadcastReceiver();

    private:
        virtual void run();
        void handleIncomingAllResources(BroadcastAllResources &msg);
        void handleIncomingResource(BroadcastResource &msg);
        void handleIncomingRevoke(BroadcastRevoke &msg);
};

#endif