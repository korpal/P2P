#ifndef BROADCASTREVOKE_HPP
#define BROADCASTREVOKE_HPP

#include "BroadcastMessage.hpp"

class BroadcastRevoke : public BroadcastMessage {
    public:
        BroadcastRevoke() : BroadcastMessage(BroadcastMessage::Type::REVOKE) {}
        BroadcastRevoke(char *resourceName) : BroadcastMessage(BroadcastMessage::Type::REVOKE)
        {
            this->resourceName = resourceName;
        }

        char* getResourceName() { return resourceName; }

    private:
        // TODO - temporary
        char *resourceName;
};

#endif

