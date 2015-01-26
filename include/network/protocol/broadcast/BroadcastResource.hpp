#ifndef BROADCASTRESOURCE_HPP
#define BROADCASTRESOURCE_HPP

#include <string.h>
#include "BroadcastMessage.hpp"
#include "../../../resourcemanager/ResourceIdentifier.hpp"

class BroadcastResource : public BroadcastMessage {
    public:
        BroadcastResource();
        BroadcastResource(ResourceIdentifier &ri);

        ResourceIdentifier& getResourceIdentifier();

    private:
        ResourceIdentifier resourceIdentifier;
};

#endif
