#ifndef UNICASTSENDER_HPP
#define UNICASTSENDER_HPP

#include "../utils/Thread.hpp"


class UnicastSender : public Thread {
public:
    UnicastSender();
    virtual ~UnicastSender();

    void requestRequest(char *msg, char *address);
    void requestConfirmation(char *msg, char *address);
    void requestPartRequest(char *address);
    void requestPart(char *address);

private:
    int sock;

    virtual void run();

    int createSocket();
};

#endif