#ifndef CONTROLLERSTRATEGY_H
#define CONTROLLERSTRATEGY_H

#include "controller.h"

class Controller;

class ControllerStrategy
{
    public:
        virtual void react(Event* event, Controller *controller);
        ControllerStrategy();
};


class StringStrategy: public ControllerStrategy
{
    public:
        virtual void react(Event* event, Controller *controller);
};


class PartStrategy: public ControllerStrategy
{
    public:
        virtual void react(Event* event, Controller *controller);
};


#endif