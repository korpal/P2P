#ifndef UNICASTREQUEST_HPP
#define UNICASTREQUEST_HPP

#include <string.h>
#include "UnicastMessage.hpp"

class UnicastRequest : public UnicastMessage {
    public:
        UnicastRequest() : UnicastMessage(UnicastMessage::Type::REQUEST) {}
        UnicastRequest(char rn[25]) : UnicastMessage(UnicastMessage::Type::REQUEST)
        {
            memcpy(resourceName, rn, 25);
        }

        char* getResourceName() { return resourceName; }

    private:
        // TODO - temporary
        char resourceName[25];
};

#endif
