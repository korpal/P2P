#include <iostream>

#include "../../include/network/BroadcastSender.hpp"
#include "../../include/network/BroadcastReceiver.hpp"



int main() {
    BroadcastReceiver *receiver = new BroadcastReceiver();
    receiver->start();

    getchar();

    BroadcastSender *sender = new BroadcastSender();
    sender->requestAllResources();
    sender->requestResource((char*)"some name");
    sender->requestRevoke();


    getchar();
    receiver->stop();
    receiver->join();
    delete receiver;
    delete sender;
    return 0;
}
