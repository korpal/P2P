#include <chrono>
#include "../../include/resourcemanager/DownloadedResource.hpp"

DownloadedResource::DownloadedResource(const ResourceIdentifier &identifier) :
        identifier(identifier),
        file(identifier.getName().c_str()),
        partsDownloaded(getPartsCount(), false),
        partsTimeout(getPartsCount(), 0)
{
}

void DownloadedResource::addDownloadedPart(const Part& part)
{
    file.seekp(part.getId()*Configuration::PART_SIZE, std::ios::beg);
    file.write((char*)part.getData(), part.getSize());
    partsDownloaded[part.getId()] = true;

    if(isComplete())
    {
        file.flush();
        file.close();
    }
}

bool DownloadedResource::isComplete()
{
    for(int i = getPartsCount()-1; i >= 0; --i)
        if(!partsDownloaded[i])
            return false;
    return true;
}

unsigned DownloadedResource::getPartsCount()
{
    return (unsigned int) ceil((double)identifier.getSize() / (double)Configuration::PART_SIZE);
}

int DownloadedResource::getIdOfPartForDownloading()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    unsigned long long actualTime = (unsigned long long)(tv.tv_sec) * 1000 + (unsigned long long)(tv.tv_usec) / 1000;

    for(int i = 0; i < getPartsCount(); i++)
    {
        if(partsTimeout[i] < actualTime)
        {
            partsTimeout[i] = actualTime + Configuration::PARTS_TIMEOUT_IN_SECONDS*1000;
            return i;
        }
    }
    for(int i = 0; i < getPartsCount(); i++)
    {
        if(!partsDownloaded[i])
        {
            partsTimeout[i] = actualTime + Configuration::PARTS_TIMEOUT_IN_SECONDS*1000;
            return i;
        }
    }
    // If we are here - we have all parts.
    return -1;
}
