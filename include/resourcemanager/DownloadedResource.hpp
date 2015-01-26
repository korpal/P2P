#ifndef DOWNLOADED_RESOURCE
#define DOWNLOADED_RESOURCE

#include "boost/date_time/posix_time/posix_time.hpp"
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

private:
    bool isComplete();
    unsigned getPartsCount();

    mutable std::ofstream file;
    ResourceIdentifier identifier;

    std::vector<bool> partsDownloaded;
    std::vector<unsigned long long> partsTimeout;
};

#endif // DOWNLOADED_RESOURCE