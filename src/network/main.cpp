#include <iostream>
#include <stdio.h>
#include <netinet/in.h>

#include "../../include/network/BroadcastSender.hpp"
#include "../../include/network/BroadcastReceiver.hpp"
#include "../../include/network/UnicastReceiver.hpp"
#include "../../include/network/UnicastSender.hpp"
#include "../../include/resourcemanager/ResourceManager.hpp"
#include "../../include/resourcemanager/Source.hpp"
#include "../../include/resourcemanager/DownloadedResource.hpp"


int main()
{

    //ResourceManager resourceManager;
    //ResourceIdentifier resourceIdentifier;
    //resourceManager.addRemote(ResourceIdentifier("nam",2), Source(sockaddr_in()));
    BroadcastReceiver *broadcastReceiver = new BroadcastReceiver();
    broadcastReceiver->start();
    UnicastReceiver *unicastReceiver = new UnicastReceiver();
    unicastReceiver->start();
    getchar();

    //BroadcastSender *broadcastSender = new BroadcastSender;
    //broadcastSender->requestAllResources();

    UnicastSender *unicastSender = new UnicastSender();

    LocalResource lr("test.txt");
    Part p1 = lr.getPart(0);
    Part p2 = lr.getPart(1);
    //unicastSender->requestConfirmation((char*)"Siema", (char *)"25.9.227.212");
    unicastSender->requestPart(&p1, (char *)"192.168.2.107");
    unicastSender->requestPart(&p2, (char *)"192.168.2.107");
    //DownloadedResource dr(p1.getResourceIdentifier());
    //dr.addDownloadedPart(p1);
    //dr.addDownloadedPart(p2);
    fflush(stdout);

    getchar();
    broadcastReceiver->stop();
    broadcastReceiver->join();
    unicastReceiver->stop();
    unicastReceiver->join();
    delete broadcastReceiver;
    delete unicastReceiver;
    //delete broadcastSender;
    //delete unicastSender;
    return 0;
}
