#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <unordered_map>
#include <typeinfo>
#include <typeindex>

class ControllerStrategy;

#include "../../include/controller/event_queue.hpp"
#include "event_queue.hpp"
#include "../utils/Thread.hpp"
#include "../resourcemanager/ResourceManager.hpp"
#include "ControllerStrategy.hpp"


class Controller : public Thread
{
    private:
        EventQueue* const event_queue;
        std::unordered_map<std::type_index, ControllerStrategy*> strategyMap;

    public:
        Controller(EventQueue* const);
        ~Controller();
        virtual void run();
};



#endif
