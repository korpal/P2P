#ifndef UNICASTRECEIVER_HPP
#define UNICASTRECEIVER_HPP

#include "../utils/Thread.hpp"
#include "protocol/unicast/UnicastRequest.hpp"
#include "protocol/unicast/UnicastConfirmation.hpp"
#include "protocol/unicast/UnicastPartRequest.hpp"
#include "protocol/unicast/UnicastPart.hpp"


class UnicastReceiver : public Thread {
    public:
        UnicastReceiver();
        virtual ~UnicastReceiver();

    private:
        virtual void run();
        void handleIncomingRequest(UnicastRequest &msg);
        void handleIncomingConfirmation(UnicastConfirmation &msg);
        void handleIncomingPartRequest(UnicastPartRequest &msg);
        void handleIncomingPart(UnicastPart &msg);
};

#endif
