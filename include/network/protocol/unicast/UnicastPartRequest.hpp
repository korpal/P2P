#ifndef UNICASTPARTREQUEST_HPP
#define UNICASTPARTREQUEST_HPP

#include "UnicastMessage.hpp"

class UnicastPartRequest : public UnicastMessage {
    public:
        UnicastPartRequest() : UnicastMessage(UnicastMessage::Type::PARTREQUEST) {}

};

#endif
