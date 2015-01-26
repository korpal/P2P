#include <iostream>
#include <cstring>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#include "../../include/network/UnicastSender.hpp"
#include "../../include/network/protocol/unicast/UnicastPart.hpp"
#include "../../include/network/protocol/unicast/UnicastPartRequest.hpp"
#include "../../include/network/protocol/unicast/UnicastResource.hpp"



UnicastSender::UnicastSender()
{
    sock = createSocket();
}

UnicastSender::UnicastSender(UnicastSender const &unicastSender) {}

UnicastSender::~UnicastSender(){}


UnicastSender &UnicastSender::getInstance()
{
    static UnicastSender unicastSender;
    return unicastSender;
}



void UnicastSender::run() {}



void UnicastSender::sendResource(ResourceIdentifier &ri, char *address)
{
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(Configuration::UNICAST_PORT);
    addr.sin_addr.s_addr = inet_addr(address);

    UnicastResource *msg = new UnicastResource(ri);

    if(sendto(sock, msg, sizeof(*msg), 0, (struct sockaddr *)&addr, sizeof(addr)) < 0)
        std::cout<<"Sending UnicastResource failed";
}


void UnicastSender::sendPartRequest(char *address)
{
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(Configuration::UNICAST_PORT);
    addr.sin_addr.s_addr = inet_addr(address);

    UnicastPartRequest *msg = new UnicastPartRequest();

    if(sendto(sock, msg, sizeof(*msg), 0, (struct sockaddr *)&addr, sizeof(addr)) < 0)
        std::cout<<"Sending UnicastPartRequest failed";
}


void UnicastSender::sendPart(Part *part, char *address)
{
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(Configuration::UNICAST_PORT);
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


