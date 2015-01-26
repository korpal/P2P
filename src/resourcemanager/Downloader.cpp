#include "../../include/resourcemanager/Downloader.hpp"

Downloader::Downloader(boost::shared_ptr<DownloadedResource> downloadedResource) :
    downloadedResource(downloadedResource)
{
    downloaders.insert(
            std::pair<boost::shared_ptr<DownloadedResource>,
                    boost::shared_ptr<Downloader>>
                    (downloadedResource, this));
}

void Downloader::run()
{
    while(!isFinished())
    {
        int partId = downloadedResource->getIdOfPartForDownloading();
        // Get Sources
        //
    }
}