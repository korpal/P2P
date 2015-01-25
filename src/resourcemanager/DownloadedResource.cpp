#include "../../include/resourcemanager/DownloadedResource.hpp"

DownloadedResource::DownloadedResource(const ResourceIdentifier &identifier) :
        identifier(identifier),
        partsDownloaded(getPartsCount(), false)
{

}

void DownloadedResource::addDownloadedPart(const Part& part)
{
    file.seekp(part.getId()*Configuration::PART_SIZE, std::ios::beg);
    file.write((char*)part.getData(), part.getSize());
    partsDownloaded[part.getId()] = true;
}

bool DownloadedResource::isComplete() const
{

}

unsigned DownloadedResource::getPartsCount()
{
    if(!partsCount)
        partsCount = (identifier.getSize() + Configuration::PART_SIZE )
                        / Configuration::PART_SIZE;
    return partsCount;
}