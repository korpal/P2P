
#include "../../include/controller/ControllerStrategy.hpp"
#include "../../include/resourcemanager/ResourceManager.hpp"

ControllerStrategy::ControllerStrategy() {}

void ControllerStrategy::react(Event* event) {}

void PartStrategy::react(Event* event)
{
//    PartEvent* partEvent = dynamic_cast<PartEvent*>(event);
//    ResourceManager::getInstance().receivePart(partEvent->getPart());
}

void TransformDownloadedResourceStrategy::react(Event *event)
{
    TransformEvent* transformEvent = dynamic_cast<TransformEvent*>(event);
    ResourceManager::getInstance().transformDownloadedIntoLocal(transformEvent->getIdentifier());
}