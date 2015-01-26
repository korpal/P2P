#include "../../../../include/network/protocol/broadcast/BroadcastResource.hpp"


BroadcastResource::BroadcastResource() : BroadcastMessage(BroadcastMessage::Type::RESOURCE) {}

BroadcastResource::BroadcastResource(ResourceIdentifier &ri) :
        BroadcastMessage(BroadcastMessage::Type::RESOURCE),
        resourceIdentifier(ri)
{}


ResourceIdentifier& BroadcastResource::getResourceIdentifier()
{
    return resourceIdentifier;
}