#include "../../../../include/network/protocol/unicast/UnicastResource.hpp"



UnicastResource::UnicastResource() : UnicastMessage(UnicastMessage::Type::RESOURCE) {}


UnicastResource::UnicastResource(ResourceIdentifier &ri) :
        UnicastMessage(UnicastMessage::Type::RESOURCE),
        resourceIdentifier(ri)
{
}

ResourceIdentifier &UnicastResource::getResourceIdentifier() {
    return resourceIdentifier;
}
