#ifndef EVENTS_H
#define EVENTS_H

#include <string>


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
        std::string message;
    public:
        virtual ~PartEvent();
        virtual std::string getMessage();
        PartEvent(std::string message);
};


#endif
