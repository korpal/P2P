#include <iostream>
#include <stdio.h>

#include "../../include/network/BroadcastSender.hpp"
#include "../../include/network/BroadcastReceiver.hpp"
#include "../../include/network/UnicastReceiver.hpp"
#include "../../include/network/UnicastSender.hpp"


int main()
{
    BroadcastReceiver *broadcastReceiver = new BroadcastReceiver();
    broadcastReceiver->start();
    UnicastReceiver *unicastReceiver = new UnicastReceiver();
    unicastReceiver->start();

    getchar();

    BroadcastSender *broadcastSender = new BroadcastSender();
    //broadcastSender->requestAllResources();
    //broadcastSender->requestResource((char*)"some name");
    //broadcastSender->requestRevoke();

    UnicastSender *unicastSender = new UnicastSender();
    unicastSender->requestRequest((char*)"Siema Heniu", (char *)"192.168.2.107");
    //unicastSender->requestPart((char *)"25.9.227.212");


    getchar();
    broadcastReceiver->stop();
    broadcastReceiver->join();
    unicastReceiver->stop();
    unicastReceiver->join();
    delete broadcastReceiver;
    delete unicastReceiver;
    delete broadcastSender;
    delete unicastSender;
    return 0;
}
