#include "../../include/controller/ControllerStrategy.hpp"
#include "../../include/controller/events.h"
#include "../../include/controller/controller.h"

ControllerStrategy::ControllerStrategy() {}

void ControllerStrategy::react(Event* event, Controller *controller) {}


void StringStrategy::react(Event* event, Controller *controller)
{
    StringEvent* stringEven = dynamic_cast<StringEvent*>(event);
    printf("Siema, dostalem stringEvent\n");
    fflush(stdout);
}


void PartStrategy::react(Event* event, Controller *controller)
{
    PartEvent* partEvent = dynamic_cast<PartEvent*>(event);
    controller->getResourceManager()->receivePart(partEvent->getPart());
}



