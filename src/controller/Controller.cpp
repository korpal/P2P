#include <typeindex>
#include <iostream>
#include <utility>

#include "Controller.hpp"
#include "../../include/controller/ControllerStrategy.hpp"


Controller::Controller(EventQueue* const event_queue) :
        event_queue(event_queue)
{
    this->strategyMap.insert(std::make_pair<std::type_index, StringStrategy*>
            (std::type_index(typeid(StringEvent)), new StringStrategy()));
    this->strategyMap.insert(std::make_pair<std::type_index, PartStrategy*>
            (std::type_index(typeid(PartEvent)), new PartStrategy()));
}

Controller::~Controller() {}

void Controller::run()
{
    while(!isFinished())
    {
        Event* event = event_queue->pop();
        ControllerStrategy* strategy =
            strategyMap[std::type_index(typeid(*event))];
        strategy->react(event);
    }
}



