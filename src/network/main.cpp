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

    ResourceManager resourceManager;
    ResourceIdentifier resourceIdentifier;
    resourceManager.addRemoteResource(ResourceIdentifier("nam",2), Source(sockaddr_in()));

    BroadcastReceiver *broadcastReceiver = new BroadcastReceiver();
    broadcastReceiver->start();
    UnicastReceiver *unicastReceiver = new UnicastReceiver();
    unicastReceiver->start();
    getchar();

    //BroadcastSender *broadcastSender = new BroadcastSender;
    //broadcastSender->requestAllResources();

    //UnicastSender *unicastSender = new UnicastSender();

    LocalResource lr("test.txt");
    Part p1 = lr.getPart(0);
    Part p2 = lr.getPart(1);
    Part p3 = lr.getPart(2);
    //unicastSender->requestPart(&p1, (char *)"25.1.3.6");
    //unicastSender->requestPart(&p2, (char *)"25.1.3.6");
    //unicastSender->requestPart(&p3, (char *)"25.1.3.6");
    DownloadedResource dr(p1.getResourceIdentifier());
    std::cout << dr.getIdOfPartForDownloading() << " " << dr.getIdOfPartForDownloading() << " " << dr.getIdOfPartForDownloading() << " " << dr.getIdOfPartForDownloading() << std::endl;
    dr.addDownloadedPart(p1);
    dr.addDownloadedPart(p2);
    dr.addDownloadedPart(p3);
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
