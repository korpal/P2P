#ifndef UNICASTSENDER_HPP
#define UNICASTSENDER_HPP

#include "../utils/Thread.hpp"


class UnicastSender : public Thread {
public:
    UnicastSender();
    virtual ~UnicastSender();

    void requestRequest(char *msg);
    void requestConfirmation(char *msg);
    void requestPartRequest();
    void requestPart();

private:
    int sock;

    virtual void run();

    int createSocket();
};

#endif