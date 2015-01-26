#ifndef UNICASTSENDER_HPP
#define UNICASTSENDER_HPP

#include "../utils/Thread.hpp"
#include "../resourcemanager/Part.hpp"


class UnicastSender : public Thread {
public:
    UnicastSender();
    virtual ~UnicastSender();

    void sendResource(ResourceIdentifier &ri, char *address);
    void sendPartRequest(char *address);
    void sendPart(Part *part, char *address);

private:
    int sock;

    virtual void run();

    int createSocket();
};

#endif