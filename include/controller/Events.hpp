#ifndef EVENTS_H
#define EVENTS_H

#include <string>
#include "../resourcemanager/Part.hpp"
#include "../resourcemanager/Source.hpp"


class Event
{
    public:
        virtual ~Event();
};


class OutgoingAllResourcesRequestEvent : public Event
{
    public:
        OutgoingAllResourcesRequestEvent() {}
};


class IncomingAllResourcesRequestEvent : public Event
{
    public:
        IncomingAllResourcesRequestEvent() {}
};


class OutgoingResourceRequestEvent : public Event
{
    public:
        OutgoingResourceRequestEvent(ResourceIdentifier &ri);
        ResourceIdentifier& getResourceIdentifier();
    private:
        ResourceIdentifier& resourceIdentifier;
};


class IncomingResourceRequestEvent : public Event
{
    public:
        IncomingResourceRequestEvent(ResourceIdentifier &ri);
        ResourceIdentifier& getResourceIdentifier();
    private:
        ResourceIdentifier& resourceIdentifier;
};


class OutgoingRevokeRequestEvent : public Event
{
    public:
        OutgoingRevokeRequestEvent(ResourceIdentifier &ri);
        ResourceIdentifier& getResourceIdentifier();
    private:
        ResourceIdentifier& resourceIdentifier;
};


class IncomingRevokeRequestEvent : public Event
{
    public:
        IncomingRevokeRequestEvent(ResourceIdentifier &ri);
        ResourceIdentifier& getResourceIdentifier();
    private:
        ResourceIdentifier& resourceIdentifier;
};


class OutgoingRevertRequestEvent : public Event
{
    public:
        OutgoingRevertRequestEvent(ResourceIdentifier &ri);
        ResourceIdentifier& getResourceIdentifier();
    private:
        ResourceIdentifier& resourceIdentifier;
};


class IncomingRevertRequestEvent : public Event
{
    public:
        IncomingRevertRequestEvent(ResourceIdentifier &ri);
        ResourceIdentifier& getResourceIdentifier();
    private:
        ResourceIdentifier& resourceIdentifier;
};


class IncomingPartEvent : public Event
{
    public:
        IncomingPartEvent(Part& part, Source& source);
        Part& getPart();
        Source& getSource();
    private:
        Part part;
        Source source;
};


class OutgoingPartEvent : public Event
{
    public:
        OutgoingPartEvent(Part& part, Source& source);
        Part& getPart();
        Source& getSource();
    private:
        Part part;
        Source source;
};


class IncomingPartRequestEvent : public Event
{
    public:
        IncomingPartRequestEvent(ResourceIdentifier &ri, unsigned partId);
        ResourceIdentifier& getResourceIdentifier();
        unsigned getPartId();
        Source& getSource();
    private:
        unsigned partId;
        ResourceIdentifier resourceIdentifier;
        Source source;
};


class OutgoingPartRequestEvent : public Event
{
    public:
        OutgoingPartRequestEvent(ResourceIdentifier &ri, unsigned partId);
        ResourceIdentifier& getResourceIdentifier();
        unsigned getPartId();
        Source& getSource();
    private:
        unsigned partId;
        ResourceIdentifier resourceIdentifier;
        Source source;
};


class IncomingResourceInformationEvent : public Event
{
    public:
        IncomingResourceInformationEvent(ResourceIdentifier &ri);
        ResourceIdentifier& getResourceIdentifier();
        Source& getSource();
    private:
        ResourceIdentifier resourceIdentifier;
        Source source;
};


class OutgoingResourceInformationEvent : public Event
{
    public:
        OutgoingResourceInformationEvent(ResourceIdentifier &ri);
        ResourceIdentifier& getResourceIdentifier();
        Source& getSource();
    private:
        ResourceIdentifier resourceIdentifier;
        Source source;
};


class TransformEvent : public Event
{
    public:
        const ResourceIdentifier& getIdentifier();
        TransformEvent(const ResourceIdentifier& identifier);
    private:
        const ResourceIdentifier& resourceIdentifier;
};

#endif
