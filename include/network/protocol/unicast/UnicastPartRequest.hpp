#ifndef UNICASTPARTREQUEST_HPP
#define UNICASTPARTREQUEST_HPP

#include "UnicastMessage.hpp"
#include "../../../resourcemanager/Part.hpp"

class UnicastPartRequest : public UnicastMessage {
    public:
        UnicastPartRequest();
        UnicastPartRequest(ResourceIdentifier &ri, unsigned partId);

        ResourceIdentifier& getResourceIdentifier();
        unsigned getPartId();

    private:
        ResourceIdentifier resourceIdentifier;
        unsigned partId;
};

#endif
