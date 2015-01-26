#include "../../../../include/network/protocol/broadcast/BroadcastRevert.hpp"

BroadcastRevert::BroadcastRevert() : BroadcastMessage(BroadcastMessage::Type::REVERT) {}

BroadcastRevert::BroadcastRevert(ResourceIdentifier &ri) :
        BroadcastMessage(BroadcastMessage::Type::REVERT),
        resourceIdentifier(ri)
{}


ResourceIdentifier& BroadcastRevert::getResourceIdentifier()
{
    return resourceIdentifier;
}