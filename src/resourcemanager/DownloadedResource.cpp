#include "../../include/resourcemanager/DownloadedResource.hpp"

DownloadedResource::DownloadedResource(const ResourceIdentifier &identifier) :
        identifier(identifier),
        file(identifier.getName().c_str()),
        partsDownloaded(getPartsCount(), false),
        partsCount((unsigned int) ceil((double)identifier.getSize() / (double)Configuration::PART_SIZE))
{
}

void DownloadedResource::addDownloadedPart(const Part& part)
{
    file.seekp(part.getId()*Configuration::PART_SIZE, std::ios::beg);
    file.write((char*)part.getData(), part.getSize());
    partsDownloaded[part.getId()] = true;



    if(isComplete()) {
        std::cout << "Koniec!!!";
        fflush(stdout);
        file.flush();
        file.close();
    }
    std::cout << std::endl;
}

bool DownloadedResource::isComplete()
{
    for(unsigned i = getPartsCount()-1; i >= 0; --i)
        if(!partsDownloaded[i])
            return false;
    return true;
}

unsigned DownloadedResource::getPartsCount()
{
    return partsCount;
}