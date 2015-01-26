
#include "../../include/resourcemanager/Part.hpp"


Part::Part(){}

Part::Part(const ResourceIdentifier &ri, unsigned id, unsigned size, std::istream &data_stream) :
        resourceIdentifier(ri),
        id(id),
        size(size)
{
    memset(data, 0, Configuration::PART_SIZE);
    data_stream.read((char*)data, size);
}


ResourceIdentifier& Part::getResourceIdentifier() const
{
    return resourceIdentifier;
}


unsigned Part::getId() const
{
    return id;
}


unsigned Part::getSize() const
{
    return size;
}


const uint8_t* Part::getData() const
{
    return data;
}
