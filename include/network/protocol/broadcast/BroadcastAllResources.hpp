#ifndef BROADCASTALLRESOURCES_HPP
#define BROADCASTALLRESOURCES_HPP

#include "BroadcastMessage.hpp"

class BroadcastAllResources : public BroadcastMessage {
    public:
        BroadcastAllResources() : BroadcastMessage(BroadcastMessage::Type::ALLRESOURCES) {}
};

#endif
