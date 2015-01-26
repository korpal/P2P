
#include "../../include/controller/ControllerStrategy.hpp"
#include "../../include/resourcemanager/ResourceManager.hpp"
#include "../../include/network/BroadcastSender.hpp"
#include "../../include/network/UnicastSender.hpp"

ControllerStrategy::ControllerStrategy() {}

void ControllerStrategy::react(Event* event) {}


void OutgoingAllResourcesStrategy::react(Event *event)
{
    BroadcastSender::getInstance().requestAllResources();
}


void OutgoingResourceRequestStrategy::react(Event *event)
{
    OutgoingResourceRequestEvent* event_ = dynamic_cast<OutgoingResourceRequestEvent*>(event);
    BroadcastSender::getInstance().requestResource(event_->getResourceIdentifier());
}


void OutgoingRevokeStrategy::react(Event *event)
{
    OutgoingRevokeRequestEvent* event_ = dynamic_cast<OutgoingRevokeRequestEvent*>(event);
    BroadcastSender::getInstance().requestRevoke(event_->getResourceIdentifier());
}


void OutgoingRevertStrategy::react(Event *event)
{
    OutgoingRevertRequestEvent* event_ = dynamic_cast<OutgoingRevertRequestEvent*>(event);
    BroadcastSender::getInstance().requestRevert(event_->getResourceIdentifier());
}


void OutgoingPartStrategy::react(Event *event)
{
    OutgoingPartEvent* event_ = dynamic_cast<OutgoingPartEvent*>(event);
    UnicastSender::getInstance().sendPart(&event_->getPart(), event_->getSource());
}


void OutgoingPartRequestStrategy::react(Event *event)
{
    OutgoingPartRequestEvent* event_ = dynamic_cast<OutgoingPartRequestEvent*>(event);
    UnicastSender::getInstance().sendPartRequest(event_->getResourceIdentifier(), event_->getPartId(), event_->getSource());
}


void OutgoingResourceInformationStrategy::react(Event *event)
{
    OutgoingResourceInformationEvent* event_ = dynamic_cast<OutgoingResourceInformationEvent*>(event);
    UnicastSender::getInstance().sendResource(event_->getResourceIdentifier(), event_->getSource());
}

void TransformDownloadedResourceStrategy::react(Event *event)
{
    TransformEvent* transformEvent = dynamic_cast<TransformEvent*>(event);
    ResourceManager::getInstance().transformDownloadedIntoLocal(transformEvent->getIdentifier());
}


