#ifndef UNICASTPART_HPP
#define UNICASTPART_HPP

#include "UnicastMessage.hpp"
#include "../../../resourcemanager/Part.hpp"

class UnicastPart : public UnicastMessage {
    public:
        UnicastPart() : UnicastMessage(UnicastMessage::Type::PART) {}
        UnicastPart(Part *part) : UnicastMessage(UnicastMessage::Type::PART), part(*part){}

        Part getPart() { return part; }

    private:
        // TODO - temporary
        Part part;
};

#endif
