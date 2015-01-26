#ifndef UNICASTSENDER_HPP
#define UNICASTSENDER_HPP

#include "../utils/Thread.hpp"
#include "../resourcemanager/Part.hpp"
#include "../resourcemanager/Source.hpp"


class UnicastSender : public Thread {
    public:
        static UnicastSender& getInstance();
        virtual ~UnicastSender();

        void sendResource(ResourceIdentifier &ri, Source& source);
        void sendPartRequest(ResourceIdentifier &ri, unsigned partId, Source& source);
        void sendPart(Part *part, Source& source);

    private:
        UnicastSender();
        UnicastSender(const UnicastSender&);
        virtual void run();

        int sock;
        int createSocket();
};

#endif