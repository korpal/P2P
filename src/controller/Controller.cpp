#include <typeindex>
#include <iostream>
#include <utility>

#include "../../include/controller/Controller.hpp"
#include "../../include/utils/EventQueue.hpp"


Controller::Controller()
{
/*    this->strategyMap.insert(std::make_pair<std::type_index, StringStrategy*>
            (std::type_index(typeid(StringEvent)), new StringStrategy()));
    this->strategyMap.insert(std::make_pair<std::type_index, PartStrategy*>
            (std::type_index(typeid(PartEvent)), new PartStrategy()));*/
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



