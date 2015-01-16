#include <iostream>
#include <cstring>
#include <cstdio>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#include "../../include/network/Receiver.hpp"
#include "../../include/network/BroadcastMessage.hpp"

#define PORT 8888
#define BMSIZE 165


Receiver::Receiver() {}

Receiver::~Receiver(){}

void Receiver::run()
{
    struct sockaddr_in si_me, si_other;

    int s, i, recv_len;
    socklen_t slen = sizeof(si_other);
    BroadcastMessage bm;


    if ((s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
    {
        printf("socket error");
    }

    // zero out the structure
    memset((char *) &si_me, 0, sizeof(si_me));

    si_me.sin_family = AF_INET;
    si_me.sin_port = htons(PORT);
    si_me.sin_addr.s_addr = htonl(INADDR_ANY);

    //bind socket to port
    if( bind(s , (struct sockaddr*)&si_me, sizeof(si_me) ) == -1)
    {
        printf("bind error");
    }

    while(1)
    {
        printf("Waiting for data...");
        fflush(stdout);

        //try to receive some data, this is a blocking call
        if ((recv_len = recvfrom(s, &bm, BMSIZE, 0, (struct sockaddr *) &si_other, &slen)) == -1)
        {
            printf("recvfrom() error");
        }

        //print details of the client/peer and the data received
        printf("Received packet from %s:%d\n", inet_ntoa(si_other.sin_addr), ntohs(si_other.sin_port));
        printf("Data: %s\n" , bm.getMessage().c_str());

        //now reply the client with the same data
        //if (sendto(s, bm, recv_len, 0, (struct sockaddr*) &si_other, slen) == -1)
        //{
        //    printf("sendto() error");
        //}
    }
}


