#ifndef BROADCASTRESOURCE_HPP
#define BROADCASTRESOURCE_HPP

#include "BroadcastMessage.hpp"

class BroadcastResource : public BroadcastMessage {
    public:
        BroadcastResource() : BroadcastMessage(BroadcastMessage::Type::RESOURCE) {}
        BroadcastResource(char *resourceName) : BroadcastMessage(BroadcastMessage::Type::RESOURCE)
        {
            this->resourceName = resourceName;
        }

        char* getResourceName() { return resourceName; }

    private:
        // TODO - temporary
        char *resourceName;
};

#endif
