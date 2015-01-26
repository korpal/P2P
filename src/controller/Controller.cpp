#include <typeindex>
#include <iostream>
#include <utility>

#include "../../include/controller/Controller.hpp"
#include "../../include/utils/EventQueue.hpp"


Controller::Controller()
{
    this->strategyMap.insert(std::make_pair<std::type_index, OutgoingAllResourcesStrategy*>
            (std::type_index(typeid(OutgoingAllResourcesRequestEvent)), new OutgoingAllResourcesStrategy()));
    this->strategyMap.insert(std::make_pair<std::type_index, IncomingAllResourcesStrategy*>
            (std::type_index(typeid(IncomingAllResourcesRequestEvent)), new IncomingAllResourcesStrategy()));
    this->strategyMap.insert(std::make_pair<std::type_index, OutgoingResourceRequestStrategy*>
            (std::type_index(typeid(OutgoingResourceRequestEvent)), new OutgoingResourceRequestStrategy()));
    //this->strategyMap.insert(std::make_pair<std::type_index, IncomingResourceRequestStrategy*>
    //        (std::type_index(typeid(IncomingResourceRequestEvent)), new IncomingResourceRequestStrategy()));
    this->strategyMap.insert(std::make_pair<std::type_index, IncomingRevokeStrategy*>
            (std::type_index(typeid(IncomingRevokeRequestEvent)), new IncomingRevokeStrategy()));
    this->strategyMap.insert(std::make_pair<std::type_index, OutgoingRevokeStrategy*>
            (std::type_index(typeid(OutgoingRevokeRequestEvent)), new OutgoingRevokeStrategy()));
    this->strategyMap.insert(std::make_pair<std::type_index, IncomingRevertStrategy*>
            (std::type_index(typeid(IncomingRevertRequestEvent)), new IncomingRevertStrategy()));
    this->strategyMap.insert(std::make_pair<std::type_index, OutgoingRevertStrategy*>
            (std::type_index(typeid(OutgoingRevertRequestEvent)), new OutgoingRevertStrategy()));
    this->strategyMap.insert(std::make_pair<std::type_index, IncomingPartStrategy*>
            (std::type_index(typeid(IncomingPartEvent)), new IncomingPartStrategy()));
    this->strategyMap.insert(std::make_pair<std::type_index, OutgoingPartStrategy*>
            (std::type_index(typeid(OutgoingPartEvent)), new OutgoingPartStrategy()));
    this->strategyMap.insert(std::make_pair<std::type_index, IncomingPartRequestStrategy*>
            (std::type_index(typeid(IncomingPartRequestEvent)), new IncomingPartRequestStrategy()));
    this->strategyMap.insert(std::make_pair<std::type_index, OutgoingPartRequestStrategy*>
            (std::type_index(typeid(OutgoingPartRequestEvent)), new OutgoingPartRequestStrategy()));
    this->strategyMap.insert(std::make_pair<std::type_index, IncomingResourceInformationStrategy*>
            (std::type_index(typeid(IncomingResourceInformationEvent)), new IncomingResourceInformationStrategy()));
    this->strategyMap.insert(std::make_pair<std::type_index, OutgoingResourceInformationStrategy*>
            (std::type_index(typeid(OutgoingResourceInformationEvent)), new OutgoingResourceInformationStrategy()));
    this->strategyMap.insert(std::make_pair<std::type_index, TransformDownloadedResourceStrategy*>
            (std::type_index(typeid(TransformEvent)), new TransformDownloadedResourceStrategy()));
    this->strategyMap.insert(std::make_pair<std::type_index, NewDownloaderStrategy*>
            (std::type_index(typeid(NewDownloaderEvent)), new NewDownloaderStrategy()));
    this->strategyMap.insert(std::make_pair<std::type_index, NewLocalResourceStrategy*>
            (std::type_index(typeid(NewLocalResourceEvent)), new NewLocalResourceStrategy()));

}

Controller::~Controller() {}

void Controller::run()
{
    while(!isFinished())
    {
        Event* event = EventQueue::getInstance().pop();
        ControllerStrategy* strategy =
            strategyMap[std::type_index(typeid(*event))];
        strategy->react(event);
    }
}



