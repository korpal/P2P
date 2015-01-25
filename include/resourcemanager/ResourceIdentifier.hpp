#ifndef RESOURCE_IDENTIFIER_HPP
#define RESOURCE_IDENTIFIER_HPP

#include <string>

class ResourceIdentifier
{
    public:
        ResourceIdentifier();
        ResourceIdentifier(const std::string &name, unsigned size);

        std::string& getName();
        unsigned getSize() const;
        unsigned getID() const;

        bool operator<(const ResourceIdentifier &ri) const;
        bool operator==(const ResourceIdentifier &ri) const;

    private:
        std::string name;
        unsigned size;
        unsigned hash;
};


#endif
