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
        void handleIncomingResource(UnicastResource &msg, char* address);
        void handleIncomingPartRequest(UnicastPartRequest &msg, char* address);
        void handleIncomingPart(UnicastPart &msg, char* address);
};

#endif
