#include <string>

#include "../../include/controller/Events.hpp"

Event::~Event() {}



// IncomingAllResourcesRequest //
IncomingAllResourcesRequestEvent::IncomingAllResourcesRequestEvent(Source &source) : source(source){}

Source &IncomingAllResourcesRequestEvent::getSource()
{
    return source;
}



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
IncomingPartEvent::IncomingPartEvent(Part& part, Source& source) :
        part(part),
        source(source)
{}

Part &IncomingPartEvent::getPart() {
    return part;
}

Source &IncomingPartEvent::getSource()
{
    return source;
}

// OutgoingPartEvent //
OutgoingPartEvent::OutgoingPartEvent(Part &part, Source& source) :
        part(part),
        source(source)
{}

Part &OutgoingPartEvent::getPart()
{
    return part;
}

Source &OutgoingPartEvent::getSource()
{
    return source;
}


// IncomingPartRequestEvent //
IncomingPartRequestEvent::IncomingPartRequestEvent(ResourceIdentifier &ri, unsigned partId) :
        resourceIdentifier(ri),
        partId(partId),
        source(source) {}

ResourceIdentifier &IncomingPartRequestEvent::getResourceIdentifier()
{
    return resourceIdentifier;
}

unsigned IncomingPartRequestEvent::getPartId()
{
    return partId;
}

Source &IncomingPartRequestEvent::getSource()
{
    return source;
}


// OutgoingPartRequestEvent //
OutgoingPartRequestEvent::OutgoingPartRequestEvent(ResourceIdentifier &ri, unsigned partId) :
        resourceIdentifier(ri),
        partId(partId),
        source(source) {}

ResourceIdentifier &OutgoingPartRequestEvent::getResourceIdentifier()
{
    return resourceIdentifier;
}

unsigned OutgoingPartRequestEvent::getPartId()
{
    return partId;
}

Source &OutgoingPartRequestEvent::getSource()
{
    return source;
}


// IncomingResourceInformationEvent //
IncomingResourceInformationEvent::IncomingResourceInformationEvent(ResourceIdentifier &ri) :
        resourceIdentifier(ri),
        source(source){}

ResourceIdentifier &IncomingResourceInformationEvent::getResourceIdentifier()
{
    return resourceIdentifier;
}

Source &IncomingResourceInformationEvent::getSource()
{
    return source;
}


// OutgoingResourceInformationEvent//
OutgoingResourceInformationEvent::OutgoingResourceInformationEvent(ResourceIdentifier &ri, Source& source) :
        resourceIdentifier(ri),
        source(source){}

ResourceIdentifier &OutgoingResourceInformationEvent::getResourceIdentifier()
{
    return resourceIdentifier;
}

Source &OutgoingResourceInformationEvent::getSource()
{
    return source;
}


// TransformEvent //
TransformEvent::TransformEvent(const ResourceIdentifier &identifier) :
    resourceIdentifier(identifier) {}

const ResourceIdentifier& TransformEvent::getIdentifier()
{
    return resourceIdentifier;
}


// NewDownloadResourceEvent //
NewDownloadResourceEvent::NewDownloadResourceEvent(
        boost::shared_ptr<DownloadedResource> downloadedResource) :
    downloadedResource(downloadedResource) {}

boost::shared_ptr<DownloadedResource> NewDownloadResourceEvent::getResourcePtr()
{
    return downloadedResource;
}


// DownloadedPartEvent //
DownloadedPartEvent::DownloadedPartEvent(
        const ResourceIdentifier &identifier, unsigned partId) :
    resourceIdentifier(identifier),
    partId(partId) {}

const ResourceIdentifier& DownloadedPartEvent::getIdentifier()
{
    return resourceIdentifier;
}


