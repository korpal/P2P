#include "../../include/controller/ControllerStrategy.hpp"
#include "../../include/resourcemanager/ResourceManager.hpp"
#include "../../include/controller/Events.hpp"

ControllerStrategy::ControllerStrategy() {}

void ControllerStrategy::react(Event* event) {}


void StringStrategy::react(Event* event)
{
    StringEvent* stringEven = dynamic_cast<StringEvent*>(event);
    printf("Siema, dostalem stringEvent\n");
    fflush(stdout);
}


void PartStrategy::react(Event* event)
{
    PartEvent* partEvent = dynamic_cast<PartEvent*>(event);
    ResourceManager::getInstance().receivePart(partEvent->getPart());
}



