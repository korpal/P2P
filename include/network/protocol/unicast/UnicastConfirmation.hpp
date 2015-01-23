#ifndef UNICASTCONFIRMATION_HPP
#define UNICASTCONFIRMATION_HPP

#include "UnicastMessage.hpp"

class UnicastConfirmation : public UnicastMessage {
    public:
        UnicastConfirmation() : UnicastMessage(UnicastMessage::Type::CONFIRMATION) {}
        UnicastConfirmation(char *resourceName) : UnicastMessage(UnicastMessage::Type::CONFIRMATION)
        {
            this->resourceName = resourceName;
        }

        char* getResourceName() { return resourceName; }

    private:
        // TODO - temporary
        char *resourceName;
};

#endif
