#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <boost/smart_ptr/shared_ptr.hpp>
#include "../utils/Thread.hpp"
#include "../../include/resourcemanager/Source.hpp"
#include "DownloadedResource.hpp"
#include "../utils/TimedBlockingQueue.hpp"
#include <map>

class Downloader : public Thread
{
private:
    boost::shared_ptr<DownloadedResource> downloadedResource;
    TimedBlockingQueue<Source> sourcesQueue;
    std::map<Source&, unsigned long long> sourcesTimeouts;
    std::vector<Source> sources;

public:
    static std::map<boost::shared_ptr<DownloadedResource>, boost::shared_ptr<Downloader>> downloaders;
    Downloader(boost::shared_ptr<DownloadedResource> downloadedResource);
    void run();
    void notifyAboutSource(Source& source);
};

#endif // DOWNLOADER_H