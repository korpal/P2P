#include "../../../../include/network/protocol/unicast/UnicastPartRequest.hpp"

UnicastPartRequest::UnicastPartRequest() : UnicastMessage(UnicastMessage::Type::PARTREQUEST) {}

UnicastPartRequest::UnicastPartRequest(ResourceIdentifier &ri, unsigned partId) :
        UnicastMessage(UnicastMessage::Type::PARTREQUEST),
        resourceIdentifier(ri),
        partId(partId)
{}


ResourceIdentifier& UnicastPartRequest::getResourceIdentifier()
{
    return resourceIdentifier;
}


unsigned UnicastPartRequest::getPartId()
{
    return partId;
}
