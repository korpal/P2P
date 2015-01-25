#ifndef RESOURCE_IDENTIFIER_HPP
#define RESOURCE_IDENTIFIER_HPP

#include <string>

class ResourceIdentifier
{
    public:
        ResourceIdentifier();
        ResourceIdentifier(const std::string &name, int size);
        std::string& getName();
        int getSize() const;
        std::string getID() const;
        bool operator<(const ResourceIdentifier &ri) const;
        bool operator==(const ResourceIdentifier &ri) const;

    private:
        std::string name;
        int size;
};


#endif
