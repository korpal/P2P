#include <boost/filesystem.hpp>

#include "../../include/resourcemanager/LocalResource.hpp"
#include "../../include/resourcemanager/ResourceIdentifier.hpp"


LocalResource::LocalResource(const std::string &path)
{
    boost::filesystem::path fpath(path);
    if(!boost::filesystem::exists(fpath) || !boost::filesystem::is_regular_file(fpath))
        throw "Invalid file";
    std::string name = fpath.filename().string();
    int size = (int)boost::filesystem::file_size(fpath);
    ResourceIdentifier ri(name, size);
    this->resourceIdentifier = ri;
}


LocalResource::~LocalResource()
{
    file.close();
}


Part& LocalResource::getPart(int id) const
{
/*    int partSize = getPartSize(id);

    resFile_.seekg(id*Configuration::getInstance().getPartSize(), std::ios::beg);

    return PPart(new Part(getIdentifier(), part_id, part_size, resFile_));*/
}

/*

Part::Size Resource::getPartSize(Part::Id part_id) const
{
    const ResourceIdentifier::Size s = resIdent_.getSize();
    const unsigned part_size = Configuration::getInstance().getPartSize();
    const unsigned full_parts_num = s / part_size;

    if(part_id < full_parts_num)
        return part_size;
    else
        return s % part_size;
}
*/


ResourceIdentifier& LocalResource::getResourceIdentifier()
{
    return resourceIdentifier;
}