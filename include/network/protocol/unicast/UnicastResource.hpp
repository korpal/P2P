#ifndef UNICASTCONFIRMATION_HPP
#define UNICASTCONFIRMATION_HPP

#include "UnicastMessage.hpp"
#include "../../../resourcemanager/ResourceIdentifier.hpp"

class UnicastResource : public UnicastMessage {
    public:
        UnicastResource();
        UnicastResource(ResourceIdentifier &ri);

        ResourceIdentifier& getResourceIdentifier();

    private:
        ResourceIdentifier resourceIdentifier;
};

#endif
