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
//
//    ResourceIdentifier s("Victory2.mp3",461824);
//    ResourceManager::getInstance().addDownloadedResource(s);
//
//    ResourceManager::getInstance().addLocalResource("Victory.mp3");


//    ResourceIdentifier *ri = new ResourceIdentifier("Victory2.mp3", 461824);
//    char *address = "25.1.3.6";
//    ResourceManager::getInstance().addRemoteResource(*ri, *(new Source(address)));
//    ResourceManager::getInstance().addDownloadedResource(*ri);

    //ResourceManager::getInstance().addLocalResource("Victory.mp3");

    getchar();
    return 0;
}
