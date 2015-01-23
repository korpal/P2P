#ifndef UNICASTPART_HPP
#define UNICASTPART_HPP

#include "UnicastMessage.hpp"

class UnicastPart : public UnicastMessage {
    public:
        UnicastPart() : UnicastMessage(UnicastMessage::Type::PART) {}
        UnicastPart(char *part) : UnicastMessage(UnicastMessage::Type::PART)
        {
            this->part = part;
        }

        char* getPart() { return part; }

    private:
        // TODO - temporary
        char *part;
};

#endif
