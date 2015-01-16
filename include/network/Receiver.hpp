#ifndef RECEIVER_HPP
#define RECEIVER_HPP

#include "../utils/Thread.hpp"


class Receiver : public Thread {
    public:
        Receiver();
        virtual ~Receiver();

    private:

        virtual void run();

};

#endif
