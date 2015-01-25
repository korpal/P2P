
#include "../../include/resourcemanager/Part.hpp"


Part::Part(){}

Part::Part(const ResourceIdentifier &ri, unsigned id, unsigned size, std::istream &data_stream) :
        resourceIdentifier(ri)
{
    this->id = id;
    this->size = size;
}


ResourceIdentifier& Part::getResourceIdentifier()
{
    return resourceIdentifier;
}


unsigned Part::getId()
{
    return id;
}


unsigned Part::getSize()
{
    return size;
}


uint8_t* Part::getData()
{
    return data;
}
