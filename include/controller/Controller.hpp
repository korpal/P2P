#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <unordered_map>
#include <typeinfo>
#include <typeindex>

class ControllerStrategy;

#include "../utils/Thread.hpp"
#include "ControllerStrategy.hpp"


class Controller : public Thread
{
    private:
        std::unordered_map<std::type_index, ControllerStrategy*> strategyMap;

    public:
        Controller();
        ~Controller();
        virtual void run();
};



#endif
