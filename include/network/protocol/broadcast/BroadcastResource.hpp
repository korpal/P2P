#ifndef BROADCASTRESOURCE_HPP
#define BROADCASTRESOURCE_HPP

#include <string.h>
#include "BroadcastMessage.hpp"

class BroadcastResource : public BroadcastMessage {
    public:
        BroadcastResource() : BroadcastMessage(BroadcastMessage::Type::RESOURCE) {}
        BroadcastResource(char rn[25]) : BroadcastMessage(BroadcastMessage::Type::RESOURCE)
        {
            memcpy(resourceName, rn, 25);
        }

        char* getResourceName() { return resourceName; }

    private:
        // TODO - temporary
        char resourceName[25];
};

#endif
