#ifndef UNICASTREQUEST_HPP
#define UNICASTREQUEST_HPP

#include "UnicastMessage.hpp"

class UnicastRequest : public UnicastMessage {
    public:
        UnicastRequest() : UnicastMessage(UnicastMessage::Type::REQUEST) {}
        UnicastRequest(char *resourceName) : UnicastMessage(UnicastMessage::Type::REQUEST)
        {
            this->resourceName = resourceName;
        }

        char* getResourceName() { return resourceName; }

    private:
        // TODO - temporary
        char *resourceName;
};

#endif
