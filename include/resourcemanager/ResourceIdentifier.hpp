#ifndef RESOURCE_IDENTIFIER_HPP
#define RESOURCE_IDENTIFIER_HPP

#include <string>
#include "../utils/Configuration.hpp"

class ResourceIdentifier
{
    public:
        ResourceIdentifier();
        ResourceIdentifier(const std::string &name, unsigned size);

        std::string& getName() const;
        unsigned getSize() const;
        unsigned getID() const;

        bool operator<(const ResourceIdentifier &ri) const;
        bool operator==(const ResourceIdentifier &ri) const;

    private:
        char name[Configuration::MAX_FILE_NAME_LENGTH];
        unsigned size;
        unsigned hash;
};


#endif
