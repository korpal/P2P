#include <string.h>
#include "../../include/resourcemanager/Source.hpp"

Source::Source(char* address)
{
    memcpy(this->address, address, 14);
}

std::string Source::getAddress()
{
    return address;
}
