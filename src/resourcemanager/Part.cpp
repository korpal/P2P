
#include "../../include/resourcemanager/Part.hpp"


Part::Part(){}

Part::Part(const ResourceIdentifier &ri, unsigned id, unsigned size, std::istream &data_stream) :
        resourceIdentifier(ri),
        id(id),
        size(size)
{
    memset(data, 0, Configuration::PART_SIZE);
    data_stream.read((char*)data, size);
    printf("Nowy part: %s\n", (char *)data);
    printf("Nazwa: %s\n", resourceIdentifier.getName().c_str());
    printf("Rozmiar: %d\n", resourceIdentifier.getSize());
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
