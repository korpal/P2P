#include "../../../../include/network/protocol/broadcast/BroadcastRevoke.hpp"
#include "../../../../include/resourcemanager/ResourceIdentifier.hpp"


BroadcastRevoke::BroadcastRevoke() :
        BroadcastMessage(BroadcastMessage::Type::REVOKE) {}

BroadcastRevoke::BroadcastRevoke(ResourceIdentifier &ri) :
        BroadcastMessage(BroadcastMessage::Type::REVOKE),
        resourceIdentifier(ri) {}


ResourceIdentifier& BroadcastRevoke::getResourceIdentifier()
{
    return resourceIdentifier;
}