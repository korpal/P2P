#include <iostream>
#include <cstdio>

#include "../../include/network/Receiver.hpp"
#include "../../include/network/Sender.hpp"
#include "../../include/network/Message.hpp"
#include "../../include/network/BroadcastMessage.hpp"
#include "../../include/utils/SynchronisedQueue.hpp"







int main() {
    Receiver *receiver = new Receiver();
    receiver->start();

    SynchronisedQueue<Message*> *squeue = new SynchronisedQueue<Message*>();

    Sender *sender = new Sender(squeue);
    sender->start();
    getchar();
    Message *bm = new BroadcastMessage("queuedMsg", 9);
    squeue->push(bm);

    getchar();

    bm = new UnicastMessage("queuedMsg2", 10);
    squeue->push(bm);
    getchar();
    delete receiver;
    return 0;
}
