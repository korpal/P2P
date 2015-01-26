#include <string>

#include "../../include/controller/Events.hpp"

Event::~Event() {}


// OutgoingResourceRequest //
OutgoingResourceRequestEvent::OutgoingResourceRequestEvent(ResourceIdentifier &ri) : resourceIdentifier(ri) {}

ResourceIdentifier &OutgoingResourceRequestEvent::getResourceIdentifier()
{
    return resourceIdentifier;
}


// IncomingResourceRequest //
IncomingResourceRequestEvent::IncomingResourceRequestEvent(ResourceIdentifier &ri) : resourceIdentifier(ri) {}

ResourceIdentifier &IncomingResourceRequestEvent::getResourceIdentifier()
{
    return resourceIdentifier;
}


// OutgoingRevokeRequest //
OutgoingRevokeRequestEvent::OutgoingRevokeRequestEvent(ResourceIdentifier &ri) : resourceIdentifier(ri) {}

ResourceIdentifier &OutgoingRevokeRequestEvent::getResourceIdentifier()
{
    return resourceIdentifier;
}


// IncomingRevokeRequest //
IncomingRevokeRequestEvent::IncomingRevokeRequestEvent(ResourceIdentifier &ri) : resourceIdentifier(ri) {}

ResourceIdentifier &IncomingRevokeRequestEvent::getResourceIdentifier()
{
    return resourceIdentifier;
}


// OutgoingRevertRequest //
OutgoingRevertRequestEvent::OutgoingRevertRequestEvent(ResourceIdentifier &ri) : resourceIdentifier(ri) {}

ResourceIdentifier &OutgoingRevertRequestEvent::getResourceIdentifier()
{
    return resourceIdentifier;
}


// IncomingRevertRequest //
IncomingRevertRequestEvent::IncomingRevertRequestEvent(ResourceIdentifier &ri) : resourceIdentifier(ri) {}

ResourceIdentifier &IncomingRevertRequestEvent::getResourceIdentifier()
{
    return resourceIdentifier;
}


// IncomingPartEvent //
IncomingPartEvent::IncomingPartEvent(Part& part) :
        part(part) {}

Part &IncomingPartEvent::getPart() {
    return part;
}


// OutgoingPartEvent //
OutgoingPartEvent::OutgoingPartEvent(Part &part) {}

Part &OutgoingPartEvent::getPart()
{
    return part;
}


// IncomingPartRequestEvent //
IncomingPartRequestEvent::IncomingPartRequestEvent(ResourceIdentifier &ri, Part &part) : resourceIdentifier(ri), part(part) {}

ResourceIdentifier &IncomingPartRequestEvent::getResourceIdentifier()
{
    return resourceIdentifier;
}

Part &IncomingPartRequestEvent::getPart()
{
    return part;
}


// OutgoingPartRequestEvent //
OutgoingPartRequestEvent::OutgoingPartRequestEvent(ResourceIdentifier &ri, Part &part) : resourceIdentifier(ri), part(part) {}

ResourceIdentifier &OutgoingPartRequestEvent::getResourceIdentifier()
{
    return resourceIdentifier;
}

Part &OutgoingPartRequestEvent::getPart()
{
    return part;
}


// IncomingResourceInformationEvent //
IncomingResourceInformationEvent::IncomingResourceInformationEvent(ResourceIdentifier &ri) {}

ResourceIdentifier &IncomingResourceInformationEvent::getResourceIdentifier()
{
    return resourceIdentifier;
}


// OutgoingResourceInformationEvent//
OutgoingResourceInformationEvent::OutgoingResourceInformationEvent(ResourceIdentifier &ri) {}

ResourceIdentifier &OutgoingResourceInformationEvent::getResourceIdentifier()
{
    return resourceIdentifier;
}


// TransformEvent //
TransformEvent::TransformEvent(const ResourceIdentifier &identifier) :
    resourceIdentifier(identifier) {}

const ResourceIdentifier& TransformEvent::getIdentifier()
{
    return resourceIdentifier;
}



