#ifndef DOWNLOADED_RESOURCE
#define DOWNLOADED_RESOURCE

#include <boost/smart_ptr/shared_ptr.hpp>
#include <fstream>
#include "ResourceIdentifier.hpp"
#include "Part.hpp"

class DownloadedResource
{
public:
    DownloadedResource(const ResourceIdentifier& identifier);

    void addDownloadedPart(const Part& part);
    int getIdOfPartForDownloading();
    unsigned getPartsCount();

private:
    bool isComplete();

    mutable std::ofstream file;
    ResourceIdentifier identifier;

    std::vector<bool> partsDownloaded;
    unsigned partsCount;
    std::vector<unsigned long long> partsTimeout;
};

#endif // DOWNLOADED_RESOURCE