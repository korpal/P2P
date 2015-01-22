#ifndef BROADCASTMESSAGE_HPP
#define BROADCASTMESSAGE_HPP

class BroadcastMessage {
    public:
        enum Type
        {
            ALLRESOURCES,
            RESOURCE,
            REVOKE
        };

        BroadcastMessage() {}
        BroadcastMessage(Type type) { messageType = type; }
        Type getType() { return messageType; }

    private:
        Type messageType;
};

#endif
