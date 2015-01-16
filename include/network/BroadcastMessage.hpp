#ifndef BROADCASTMESSAGE_HPP
#define BROADCASTMESSAGE_HPP

#include "Message.hpp"

class BroadcastMessage : public Message {
    public:
        BroadcastMessage();
        BroadcastMessage(char *msg, int length);
        static const int NAME_LENGTH = 128;
        typedef char Name[NAME_LENGTH];
        std::string getMessage();

    private:
        Name message;
};

#endif
