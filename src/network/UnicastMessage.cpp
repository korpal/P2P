#include <iostream>
#include <cstring>


#include "../../include/network/UnicastMessage.hpp"

UnicastMessage::UnicastMessage() {}

UnicastMessage::UnicastMessage(char *msg, int length) {
    memset(&message, 0, sizeof(message));
    //memset(&message, 0, sizeof(message));
    memcpy(&message, msg, length);
}

std::string UnicastMessage::getMessage() {
    char msg[NAME_LENGTH];
    memcpy(msg, &message, sizeof(message));
    return msg;
}

