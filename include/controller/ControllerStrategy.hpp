#ifndef CONTROLLERSTRATEGY_H
#define CONTROLLERSTRATEGY_H

#include "Controller.hpp"
#include "Events.hpp"

class Controller;

class ControllerStrategy
{
public:
    virtual void react(Event* event);
    ControllerStrategy();
};

class OutgoingAllResourcesStrategy: public ControllerStrategy
{
    public:
        virtual void react(Event* event);
};


class IncomingAllResourcesStrategy: public ControllerStrategy
{
    public:
        virtual void react(Event* event);
};


class OutgoingResourceRequestStrategy: public ControllerStrategy
{
    public:
        virtual void react(Event* event);
};


class IncomingResourceRequestStrategy: public ControllerStrategy
{
    public:
        virtual void react(Event* event);
};


class OutgoingRevokeStrategy: public ControllerStrategy
{
    public:
        virtual void react(Event* event);
};


class IncomingRevertStrategy: public ControllerStrategy
{
    public:
        virtual void react(Event* event);
};


class OutgoingRevertStrategy: public ControllerStrategy
{
    public:
        virtual void react(Event* event);
};


class IncomingPartStrategy: public ControllerStrategy
{
    public:
        virtual void react(Event* event);
};


class OutgoingPartStrategy: public ControllerStrategy
{
    public:
        virtual void react(Event* event);
};


class IncomingPartRequestStrategy: public ControllerStrategy
{
    public:
        virtual void react(Event* event);
};


class OutgoingPartRequestStrategy: public ControllerStrategy
{
    public:
        virtual void react(Event* event);
};


class IncomingResourceInformationStrategy: public ControllerStrategy
{
    public:
        virtual void react(Event* event);
};


class OutgoingResourceInformationStrategy: public ControllerStrategy
{
    public:
        virtual void react(Event* event);
};


class TransformDownloadedResourceStrategy: public ControllerStrategy
{
    public:
        virtual void react(Event* event);
};


#endif