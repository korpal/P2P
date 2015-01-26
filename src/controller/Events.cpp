#include <string>

#include "../../include/controller/Events.hpp"

Event::~Event()
{}


StringEvent::StringEvent(std::string message)
{
    this->message = message;
}
std::string StringEvent::getMessage()
{
    return message;
}



PartEvent::PartEvent(Part& part) :
    part(part) {}

Part &PartEvent::getPart()
{
    return part;
}


TransformEvent::TransformEvent(const ResourceIdentifier &identifier) :
    resourceIdentifier(identifier) {}

const ResourceIdentifier& TransformEvent::getIdentifier()
{
    return resourceIdentifier;
}