#ifndef UNICASTSENDER_HPP
#define UNICASTSENDER_HPP

#include "../utils/Thread.hpp"
#include "../resourcemanager/Part.hpp"


class UnicastSender : public Thread {
    public:
        static UnicastSender& getInstance();
        virtual ~UnicastSender();

        void sendResource(ResourceIdentifier &ri, char *address);
        void sendPartRequest(char *address);
        void sendPart(Part *part, char *address);

    private:
        UnicastSender();
        UnicastSender(const UnicastSender&);
        virtual void run();

        int sock;
        int createSocket();
};

#endif