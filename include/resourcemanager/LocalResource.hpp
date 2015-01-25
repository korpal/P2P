#ifndef LOCAL_RESOURCE_HPP
#define LOCAL_RESOURCE_HPP

#include <fstream>
#include <iostream>
#include "Part.hpp"


class LocalResource
{
    public:
        LocalResource(const std::string &path);
        ~LocalResource();

        Part& getPart(unsigned id) const;
        ResourceIdentifier& getResourceIdentifier();

    private:
        std::string path;
        mutable std::ifstream file;
        ResourceIdentifier resourceIdentifier;
};

#endif
