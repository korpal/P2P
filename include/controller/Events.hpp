#ifndef EVENTS_H
#define EVENTS_H

#include <string>
#include "../resourcemanager/Part.hpp"


class Event
{
    public:
        virtual ~Event();
};

class StringEvent: public Event
{
    private:
        std::string message;
    public:
        virtual ~StringEvent();
        virtual std::string getMessage();
            StringEvent(std::string message);
};


class PartEvent: public Event
{
    private:
        Part part;
    public:
        virtual ~PartEvent();
        Part& getPart();
        PartEvent(Part& part);
};


#endif
