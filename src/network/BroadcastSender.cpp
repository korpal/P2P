#include <iostream>
#include <cstring>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#include "../../include/network/BroadcastSender.hpp"
#include "../../include/network/protocol/broadcast/BroadcastAllResources.hpp"
#include "../../include/network/protocol/broadcast/BroadcastRevoke.hpp"
#include "../../include/network/UnicastSender.hpp"
#include "../../include/network/protocol/broadcast/BroadcastRevert.hpp"


BroadcastSender::BroadcastSender()
{
    sock = createSocket();
}

BroadcastSender::BroadcastSender(BroadcastSender const &broadcastSender) {}

BroadcastSender::~BroadcastSender(){}


BroadcastSender& BroadcastSender::getInstance()
{
    static BroadcastSender broadcastSender;
    return broadcastSender;
}


void BroadcastSender::run() {}


void BroadcastSender::requestAllResources()
{
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(Configuration::BROADCAST_PORT);

    //TODO - change!!
    std::string address = "25.255.255.255";
    addr.sin_addr.s_addr = inet_addr(address.c_str());//htonl(INADDR_BROADCAST);

    BroadcastAllResources *msg = new BroadcastAllResources();

    if(sendto(sock, msg, sizeof(*msg), 0, (struct sockaddr *)&addr, sizeof(addr)) < 0)
        std::cout<<"Sending BroadcastAllResources failed";
}


void BroadcastSender::requestRevoke(ResourceIdentifier &ri)
{
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(Configuration::BROADCAST_PORT);

    //TODO - change!!
    std::string address = "25.255.255.255";
    addr.sin_addr.s_addr = inet_addr(address.c_str());//htonl(INADDR_BROADCAST);

    BroadcastRevoke *msg = new BroadcastRevoke(ri);

    if(sendto(sock, msg, sizeof(*msg), 0, (struct sockaddr *)&addr, sizeof(addr)) < 0)
        std::cout<<"Sending BroadcastRevoke failed";
}


void BroadcastSender::requestRevert(ResourceIdentifier &ri)
{
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(Configuration::BROADCAST_PORT);

    //TODO - change!!
    std::string address = "25.255.255.255";
    addr.sin_addr.s_addr = inet_addr(address.c_str());//htonl(INADDR_BROADCAST);

    BroadcastRevert *msg = new BroadcastRevert(ri);

    if(sendto(sock, msg, sizeof(*msg), 0, (struct sockaddr *)&addr, sizeof(addr)) < 0)
        std::cout<<"Sending BroadcastRevert failed";
}


int BroadcastSender::createSocket()
{
    int sock_bc;
    if ((sock_bc = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
    {
        std::cout << "BroadcastSender: Socket creation error";
        return -1;
    }

    const int broadcast = 1;
    if (setsockopt(sock_bc, SOL_SOCKET, SO_BROADCAST, &broadcast, sizeof(broadcast)) == -1)
    {
        std::cout<<"BroadcastSender: Setting option for socket error";
        return -1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = 0;
    addr.sin_addr.s_addr = INADDR_ANY;

    if(bind(sock_bc, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        std::cout<<"BroadcastSender: Socket binding error";
        return -1;
    }

    return sock_bc;
}
