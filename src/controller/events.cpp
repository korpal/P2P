#include <string>

#include "../../include/controller/events.h"

Event::~Event()
{

}


StringEvent::StringEvent(std::string message)
{
    this->message = message;
}

StringEvent::~StringEvent()
{

}

std::string StringEvent::getMessage()
{
    return message;
}



PartEvent::PartEvent(std::string message)
{
    this->message = message;
}

PartEvent::~PartEvent()
{

}

std::string PartEvent::getMessage()
{
    return message;
}