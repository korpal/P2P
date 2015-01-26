#ifndef UNICASTPART_HPP
#define UNICASTPART_HPP

#include "UnicastMessage.hpp"
#include "../../../resourcemanager/Part.hpp"

class UnicastPart : public UnicastMessage {
    public:
        UnicastPart();
        UnicastPart(Part *part);

        Part& getPart();

    private:
        Part part;
};

#endif
