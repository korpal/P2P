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
    //ResourceIdentifier *ri = new ResourceIdentifier("Victory.mp3", 503200);
    //char *address = "25.9.227.212";
    //ResourceManager::getInstance().addRemoteResource(*ri, *(new Source(address)));
    //ResourceManager::getInstance().addDownloadedResource(*ri);
    //ResourceManager::getInstance().addLocalResource("Victory2.mp3");
    getchar();
    return 0;
}
