

#include "../../include/resourcemanager/ResourceIdentifier.hpp"


ResourceIdentifier::ResourceIdentifier() {}

ResourceIdentifier::ResourceIdentifier(const std::string &name, unsigned size)
{
    this->name = name;
    this->size = size;
}

std::string& ResourceIdentifier::getName()
{
    return this->name;
}

unsigned ResourceIdentifier::getSize() const
{
    return size;
}

std::string ResourceIdentifier::getID() const
{
    return std::string(name + std::to_string(size));
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
