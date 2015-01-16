#ifndef UNICASTMESSAGE_HPP
#define UNICASTMESSAGE_HPP

#include "Message.hpp"

class UnicastMessage : public Message {
    public:
        UnicastMessage();
        UnicastMessage(char *msg, int length);
        static const int NAME_LENGTH = 128;
        typedef char Name[NAME_LENGTH];
        std::string getMessage();

    private:
        Name message;
};

#endif

