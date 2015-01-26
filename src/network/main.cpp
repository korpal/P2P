#include <iostream>

#include "../../include/network/BroadcastSender.hpp"
#include "../../include/controller/Controller.hpp"
#include "../../include/utils/EventQueue.hpp"
#include "../../include/resourcemanager/ResourceManager.hpp"
#include "../../include/network/UnicastReceiver.hpp"
#include "../../include/network/BroadcastReceiver.hpp"
#include "../../include/interface/Interface.hpp"

int main()
{
    BroadcastReceiver *broadcastReceiver = new BroadcastReceiver();
    broadcastReceiver->start();
    UnicastReceiver *unicastReceiver = new UnicastReceiver();
    unicastReceiver->start();
    Controller *controller = new Controller();
    controller->start();
    Interface interf;
    interf.start();
    getchar();
    return 0;
}
