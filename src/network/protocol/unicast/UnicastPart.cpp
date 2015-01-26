#include "../../../../include/network/protocol/unicast/UnicastPart.hpp"

UnicastPart::UnicastPart() : UnicastMessage(UnicastMessage::Type::PART) {}


UnicastPart::UnicastPart(Part *part) :
        UnicastMessage(UnicastMessage::Type::PART),
        part(*part)
{}


Part& UnicastPart::getPart()
{
    return part;
}