#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <boost/smart_ptr/shared_ptr.hpp>
#include "../utils/Thread.hpp"
#include "DownloadedResource.hpp"
#include <map>

class Downloader : public Thread
{
private:
    boost::shared_ptr<DownloadedResource> downloadedResource;

public:
    static std::map<boost::shared_ptr<DownloadedResource>, boost::shared_ptr<Downloader>> downloaders;
    Downloader(boost::shared_ptr<DownloadedResource> downloadedResource);
    void run();
};

#endif // DOWNLOADER_H