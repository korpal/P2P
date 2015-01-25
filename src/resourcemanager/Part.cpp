
#include "../../include/resourcemanager/Part.hpp"


Part::Part(){}

Part::Part(const ResourceIdentifier &ri, unsigned id, unsigned size, std::istream &data_stream) :
        resourceIdentifier(ri),
        id(id),
        size(size)
{
    data_stream.read((char*)data, size);
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
