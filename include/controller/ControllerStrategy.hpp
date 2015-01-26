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

class PartStrategy: public ControllerStrategy
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