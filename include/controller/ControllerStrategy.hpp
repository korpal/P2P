#ifndef CONTROLLERSTRATEGY_H
#define CONTROLLERSTRATEGY_H

#include "controller.h"

class Controller;

class ControllerStrategy
{
    public:
        virtual void react(Event* event);
        ControllerStrategy();
};


class StringStrategy: public ControllerStrategy
{
    public:
        virtual void react(Event* event);
};


class PartStrategy: public ControllerStrategy
{
    public:
        virtual void react(Event* event);
};


#endif