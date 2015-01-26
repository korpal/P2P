#ifndef BROADCASTRECEIVER_HPP
#define BROADCASTRECEIVER_HPP

#include "../utils/Thread.hpp"
#include "protocol/broadcast/BroadcastAllResources.hpp"
#include "protocol/broadcast/BroadcastResource.hpp"
#include "protocol/broadcast/BroadcastRevoke.hpp"
#include "protocol/broadcast/BroadcastRevert.hpp"


class BroadcastReceiver : public Thread {
    public:
        BroadcastReceiver();
        virtual ~BroadcastReceiver();

    private:
        virtual void run();
        void handleIncomingAllResources(BroadcastAllResources &msg, char* address);
        void handleIncomingResource(BroadcastResource &msg);
        void handleIncomingRevoke(BroadcastRevoke &msg);
        void handleIncomingRevert(BroadcastRevert &msg);
};

#endif
