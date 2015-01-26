#include <iostream>
#include <cstring>
#include <cstdio>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#include "../../include/network/BroadcastReceiver.hpp"
#include "../../include/network/protocol/broadcast/BroadcastMessage.hpp"
#include "../../include/network/protocol/broadcast/BroadcastAllResources.hpp"
#include "../../include/network/protocol/broadcast/BroadcastResource.hpp"
#include "../../include/network/protocol/broadcast/BroadcastRevoke.hpp"

#define PORT 8888


BroadcastReceiver::BroadcastReceiver() {}

BroadcastReceiver::~BroadcastReceiver() {}


void BroadcastReceiver::run()
{
    struct sockaddr_in si_me, si_other;
    socklen_t slen = sizeof(si_other);
    int s, recv_len;
    const int buffSize = 10000;
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
        printf("Broadcast Receiver: waiting for data...\n");
        fflush(stdout);

        if ((recv_len = (int) recvfrom(s, buf, buffSize, 0, (struct sockaddr *) &si_other, &slen)) < 0)
        {
            printf("recvfrom() error");
        }

        printf("Broadcast Receiver: Received packet from %s:%d\n", inet_ntoa(si_other.sin_addr), ntohs(si_other.sin_port));
        printf("Broadcast Receiver: Size: %d\n" , recv_len);
        BroadcastMessage bm = (BroadcastMessage &)buf;

        switch(bm.getType())
        {
            case BroadcastMessage::Type::ALLRESOURCES:
                handleIncomingAllResources((BroadcastAllResources &)buf);
                break;
            case BroadcastMessage::Type::RESOURCE:
                handleIncomingResource((BroadcastResource &)buf);
                break;
            case BroadcastMessage::Type::REVOKE:
                handleIncomingRevoke((BroadcastRevoke &)buf);
                break;
        }
    }
}


void BroadcastReceiver::handleIncomingAllResources(BroadcastAllResources &msg)
{
    printf("Received BroadcastAllResources\n");
}

void BroadcastReceiver::handleIncomingResource(BroadcastResource &msg)
{
    printf("Received BroadcastResource with message: ");
    printf("%s\n", msg.getResourceIdentifier().getName().c_str());
}

void BroadcastReceiver::handleIncomingRevoke(BroadcastRevoke &msg)
{
    printf("Received BroadcastRevoke\n");
}
