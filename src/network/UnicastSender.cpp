#include <iostream>
#include <cstring>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#include "../../include/network/UnicastSender.hpp"
#include "../../include/network/protocol/unicast/UnicastConfirmation.hpp"
#include "../../include/network/protocol/unicast/UnicastPart.hpp"
#include "../../include/network/protocol/unicast/UnicastPartRequest.hpp"
#include "../../include/network/protocol/unicast/UnicastRequest.hpp"

#define PORT 8887


UnicastSender::UnicastSender()
{
    sock = createSocket();
}


UnicastSender::~UnicastSender(){}


void UnicastSender::run() {}


void UnicastSender::requestRequest(char *name, char *address)
{
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = inet_addr(address);

    UnicastRequest *msg = new UnicastRequest(name);

    if(sendto(sock, msg, sizeof(*msg), 0, (struct sockaddr *)&addr, sizeof(addr)) < 0)
        std::cout<<"Sending UnicastRequest failed";
}


void UnicastSender::requestConfirmation(char *name, char *address)
{
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = inet_addr(address);

    UnicastConfirmation *msg = new UnicastConfirmation(name);

    if(sendto(sock, msg, sizeof(*msg), 0, (struct sockaddr *)&addr, sizeof(addr)) < 0)
        std::cout<<"Sending UnicastConfirmation failed";
}


void UnicastSender::requestPartRequest(char *address)
{
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = inet_addr(address);

    UnicastPartRequest *msg = new UnicastPartRequest();

    if(sendto(sock, msg, sizeof(*msg), 0, (struct sockaddr *)&addr, sizeof(addr)) < 0)
        std::cout<<"Sending UnicastPartRequest failed";
}


void UnicastSender::requestPart(Part *part, char *address)
{
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = inet_addr(address);

    UnicastPart *msg = new UnicastPart(part);
    printf("Unicast Sender: Sending part that contains: %s\n", (char*)part->getData());

    if(sendto(sock, msg, sizeof(*msg), 0, (struct sockaddr *)&addr, sizeof(addr)) < 0)
        std::cout<<"Sending UnicastPart failed";
}



int UnicastSender::createSocket()
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

    if(bind(sock_uc, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        std::cout << "UnicastSender: Socket binding error";
        return -1;
    }

    return sock_uc;
}

