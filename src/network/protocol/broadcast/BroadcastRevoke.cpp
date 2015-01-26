#include "../../../../include/network/protocol/broadcast/BroadcastRevoke.hpp"
#include "../../../../include/resourcemanager/ResourceIdentifier.hpp"


BroadcastRevoke::BroadcastRevoke() : BroadcastMessage(BroadcastMessage::Type::RESOURCE) {}

BroadcastRevoke::BroadcastRevoke(ResourceIdentifier &ri) :
        BroadcastMessage(BroadcastMessage::Type::RESOURCE),
        resourceIdentifier(ri)
{}


ResourceIdentifier& BroadcastRevoke::getResourceIdentifier()
{
    return resourceIdentifier;
}