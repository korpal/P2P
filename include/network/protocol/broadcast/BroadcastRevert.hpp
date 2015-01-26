#ifndef BROADCASTREVERT_HPP
#define BROADCASTREVERT_HPP

#include "BroadcastMessage.hpp"
#include "../../../resourcemanager/ResourceIdentifier.hpp"

class BroadcastRevert : public BroadcastMessage
{
    public:
        BroadcastRevert();
        BroadcastRevert(ResourceIdentifier &ri);

        ResourceIdentifier& getResourceIdentifier();

    private:
        ResourceIdentifier resourceIdentifier;
};

#endif
