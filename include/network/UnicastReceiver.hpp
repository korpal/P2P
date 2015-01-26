#ifndef UNICASTRECEIVER_HPP
#define UNICASTRECEIVER_HPP

#include "../utils/Thread.hpp"
#include "protocol/unicast/UnicastPartRequest.hpp"
#include "protocol/unicast/UnicastPart.hpp"
#include "protocol/unicast/UnicastResource.hpp"


class UnicastReceiver : public Thread {
    public:
        UnicastReceiver();
        virtual ~UnicastReceiver();

    private:
        virtual void run();
        void handleIncomingResource(UnicastResource &msg);
        void handleIncomingPartRequest(UnicastPartRequest &msg);
        void handleIncomingPart(UnicastPart &msg);
};

#endif
