#include <string.h>
#include "../../include/resourcemanager/ResourceIdentifier.hpp"

ResourceIdentifier::ResourceIdentifier() {}

ResourceIdentifier::ResourceIdentifier(const std::string &name, unsigned size)
{
    strncpy(this->name, name.c_str(), sizeof(name)-1);
    this->size = size;
    this->hash = std::hash<std::string>()(std::string(name + std::to_string(size)));
}

std::string& ResourceIdentifier::getName()
{
    return *(new std::string(this->name));
}

unsigned ResourceIdentifier::getSize() const
{
    return size;
}

unsigned ResourceIdentifier::getID() const
{
    return hash;
}

bool ResourceIdentifier::operator<(const ResourceIdentifier &ri) const
{
    if(name == ri.name)
        return size < ri.size;
    else
        return name < ri.name;
}

bool ResourceIdentifier::operator==(const ResourceIdentifier &ri) const
{
    return (size == ri.size && name == ri.name);
}
