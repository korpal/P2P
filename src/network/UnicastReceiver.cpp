#include <iostream>
#include <cstring>
#include <cstdio>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#include "../../include/network/UnicastReceiver.hpp"
#include "../../include/network/protocol/unicast/UnicastMessage.hpp"
#include "../../include/network/protocol/unicast/UnicastPart.hpp"
#include "../../include/network/protocol/unicast/UnicastPartRequest.hpp"

#define PORT 8887


UnicastReceiver::UnicastReceiver() {}

UnicastReceiver::~UnicastReceiver() {}


void UnicastReceiver::run()
{
    struct sockaddr_in si_me, si_other;
    socklen_t slen = sizeof(si_other);
    int s, recv_len;
    const int buffSize = 100000;
    char buf[buffSize];

    if ((s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
    {
        printf("socket creation error");
    }

    memset((char *) &si_me, 0, sizeof(si_me));
    si_me.sin_family = AF_INET;
    si_me.sin_port = htons(PORT);
    si_me.sin_addr.s_addr = htonl(INADDR_ANY);
    if( bind(s , (struct sockaddr*)&si_me, sizeof(si_me) ) == -1)
    {
        printf("bind error");
    }

    /* TIMEOUT
    struct timeval tv;
    tv.tv_sec = 3;
    tv.tv_usec = 0;
    setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv,sizeof(struct timeval));*/

    while(!isFinished())
    {
        printf("Unicast Receiver: waiting for data...\n");
        fflush(stdout);

        if ((recv_len = recvfrom(s, buf, buffSize, 0, (struct sockaddr *) &si_other, &slen)) < 0)
        {
            printf("recvfrom() error");
        }

        printf("UnicastReceiver: Received packet from %s:%d\n", inet_ntoa(si_other.sin_addr), ntohs(si_other.sin_port));
        printf("UnicastReceiver: Size: %d\n" , recv_len);
        UnicastMessage bm = (UnicastMessage &)buf;

        switch(bm.getType())
        {
            case UnicastMessage::Type::RESOURCE:
                handleIncomingResource((UnicastResource &) buf);
                break;
            case UnicastMessage::Type::PARTREQUEST:
                handleIncomingPartRequest((UnicastPartRequest &)buf);
                break;
            case UnicastMessage::Type::PART:
                handleIncomingPart((UnicastPart &)buf);
                break;
        }
    }
}


void UnicastReceiver::handleIncomingResource(UnicastResource &msg)
{
    printf("Received UnicastResource with message: ");
    printf("%s\n", msg.getResourceIdentifier().getName().c_str());
}

void UnicastReceiver::handleIncomingPartRequest(UnicastPartRequest &msg)
{
    printf("Received UnicastPartRequest\n");
}

void UnicastReceiver::handleIncomingPart(UnicastPart &msg)
{
    printf("Received UnicastPart: Part Size: ");
    fflush(stdout);
    std::cout << msg.getPart().getSize();
    fflush(stdout);
    std::cout << " Msg: " << (char*)msg.getPart().getData();
    std::cout << ", File size: " << msg.getPart().getResourceIdentifier().getSize() << std::endl;
    fflush(stdout);
}
