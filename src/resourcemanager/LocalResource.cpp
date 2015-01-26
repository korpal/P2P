#include <boost/filesystem.hpp>

#include "../../include/resourcemanager/LocalResource.hpp"
#include "../../include/resourcemanager/ResourceIdentifier.hpp"

LocalResource::LocalResource(const std::string &path) :
        file(path.c_str())
{
    boost::filesystem::path fpath(path);
    if(!boost::filesystem::exists(fpath) || !boost::filesystem::is_regular_file(fpath))
        throw "Invalid file";
    std::string name = fpath.filename().string();
    unsigned size = (unsigned)boost::filesystem::file_size(fpath);
    ResourceIdentifier ri(name, size);
    this->resourceIdentifier = ri;
}

LocalResource::~LocalResource()
{
    file.close();
}

Part& LocalResource::getPart(unsigned id) const
{
    unsigned size = resourceIdentifier.getSize();
    unsigned partSize = Configuration::PART_SIZE;
    file.seekg(id*partSize, std::ios::beg);
    return *(new Part(resourceIdentifier, id, partSize, file));
}

ResourceIdentifier& LocalResource::getResourceIdentifier()
{
    return resourceIdentifier;
}