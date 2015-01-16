#include <iostream>
#include <cstring>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#include "../../include/network/Sender.hpp"
#include "../../include/network/BroadcastMessage.hpp"
#include "../../include/network/UnicastMessage.hpp"
#include "../../include/utils/SynchronisedQueue.hpp"

#define PORT 8888


Sender::Sender(SynchronisedQueue<Message*> *squeue)
{
    this->squeue = squeue;
    sockBC = createBroadcastSocket();
    sockUC = createLocalHostSocket();
}


Sender::~Sender(){}


void Sender::run()
{
    while(1)
    {
        Message *msg = squeue->pop();

        BroadcastMessage *bm = dynamic_cast<BroadcastMessage*>(msg);
        UnicastMessage *um = dynamic_cast<UnicastMessage*>(msg);
        if(bm != 0)
        {
            std::cout << "Sender: Odczytano z kolejki wiadomosc broadcast" << std::endl;
            sendBroadcast(bm);
        }
        if(um != 0)
        {
            std::cout << "Sender: Odczytano z kolejki wiadomosc unicast" << std::endl;
            sendUnicast(um);
        }
    }
}


void Sender::sendBroadcast(BroadcastMessage *msg)
{
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = htonl(INADDR_BROADCAST);

    if(sendto(sockBC, msg, sizeof(*msg), 0, (struct sockaddr *)&addr, sizeof(addr)) < 0)
        std::cout<<"Niepowodzenie";
}


void Sender::sendUnicast(UnicastMessage *msg)
{
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);



    if(sendto(sockUC, msg, sizeof(*msg), 0, (struct sockaddr *)&addr, sizeof(addr)) < 0)
        std::cout<<"Niepowodzenie";
}



int Sender::createBroadcastSocket()
{
    int sock_bc;
    if ((sock_bc = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
    {
        std::cout << "Could not create socket";
        return -1;
    }

    const int broadcast = 1;
    if (setsockopt(sock_bc, SOL_SOCKET, SO_BROADCAST, &broadcast, sizeof(broadcast)) == -1)
    {
        std::cout<<"Could not set socket option";
        return -1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = 0;
    addr.sin_addr.s_addr = INADDR_ANY;

    if(bind(sock_bc, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        std::cout<<"Could not bind Sender";
        return -1;
    }

    return sock_bc;
}



int Sender::createLocalHostSocket()
{
    int sock_uc;

    if ((sock_uc = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        std::cout << "Could not create socket Sender";
        return -1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = 0;
    addr.sin_addr.s_addr = INADDR_ANY;

    if(bind(sock_uc, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        std::cout<<"Could not bind Sender";
        return -1;
    }

    return sock_uc;
}



