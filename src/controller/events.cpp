#include <string>

#include "../../include/controller/events.h"

Event::~Event()
{}


StringEvent::StringEvent(std::string message)
{
    this->message = message;
}

StringEvent::~StringEvent()
{}

std::string StringEvent::getMessage()
{
    return message;
}



PartEvent::PartEvent(Part& part) :
    part(part) {}

PartEvent::~PartEvent() {}

Part &PartEvent::getPart() {
    return part;
}
