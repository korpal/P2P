#ifndef UNICASTMESSAGE_HPP
#define UNICASTMESSAGE_HPP

class UnicastMessage {
    public:
        enum Type
        {
            REQUEST,
            CONFIRMATION,
            PARTREQUEST,
            PART
        };

        UnicastMessage() {}
        UnicastMessage(Type type) { messageType = type; }
        Type getType() { return messageType; }

    private:
        Type messageType;
};

#endif
