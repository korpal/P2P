#ifndef BROADCASTREVOKE_HPP
#define BROADCASTREVOKE_HPP

#include "BroadcastMessage.hpp"

class BroadcastRevoke : public BroadcastMessage {
    public:
    BroadcastRevoke() : BroadcastMessage(BroadcastMessage::Type::REVOKE) {}
};

#endif

