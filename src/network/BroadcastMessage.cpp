#include <iostream>
#include <cstring>


#include "../../include/network/BroadcastMessage.hpp"

BroadcastMessage::BroadcastMessage() {}

BroadcastMessage::BroadcastMessage(char *msg, int length) {
    memset(&message, 0, sizeof(message));
    //memset(&message, 0, sizeof(message));
    memcpy(&message, msg, length);
}

std::string BroadcastMessage::getMessage() {
    char msg[NAME_LENGTH];
    memcpy(msg, &message, sizeof(message));
    return msg;
}
