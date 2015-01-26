#ifndef BROADCASTREVOKE_HPP
#define BROADCASTREVOKE_HPP

#include "BroadcastMessage.hpp"
#include "../../../resourcemanager/ResourceIdentifier.hpp"

class BroadcastRevoke : public BroadcastMessage {
    public:
        BroadcastRevoke();
        BroadcastRevoke(ResourceIdentifier &ri);

        ResourceIdentifier& getResourceIdentifier();

    private:
        ResourceIdentifier resourceIdentifier;
};

#endif

