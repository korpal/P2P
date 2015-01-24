#include <iostream>
#include <cstring>
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <ws2tcpip.h>
#else
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#endif

#include "../../include/network/BroadcastSender.hpp"
#include "../../include/network/protocol/broadcast/BroadcastAllResources.hpp"
#include "../../include/network/protocol/broadcast/BroadcastResource.hpp"
#include "../../include/network/protocol/broadcast/BroadcastRevoke.hpp"

#define PORT 8888


BroadcastSender::BroadcastSender()
{
    sock = createSocket();
}


BroadcastSender::~BroadcastSender(){}


void BroadcastSender::run() {}


void BroadcastSender::requestAllResources()
{
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = htonl(INADDR_BROADCAST);

    BroadcastAllResources *msg = new BroadcastAllResources();

    if(sendto(sock, msg, sizeof(*msg), 0, (struct sockaddr *)&addr, sizeof(addr)) < 0)
        std::cout<<"Sending BroadcastAllResources failed";
}


void BroadcastSender::requestResource(char *name)
{
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = htonl(INADDR_BROADCAST);

    BroadcastResource *msg = new BroadcastResource(name);

    if(sendto(sock, msg, sizeof(*msg), 0, (struct sockaddr *)&addr, sizeof(addr)) < 0)
        std::cout<<"Sending BroadcastResource failed";
}


void BroadcastSender::requestRevoke()
{
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = htonl(INADDR_BROADCAST);

    BroadcastRevoke *msg = new BroadcastRevoke();

    if(sendto(sock, msg, sizeof(*msg), 0, (struct sockaddr *)&addr, sizeof(addr)) < 0)
        std::cout<<"Sending BroadcastRevoke failed";
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

