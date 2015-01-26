#include "../../include/resourcemanager/Downloader.hpp"

std::map<boost::shared_ptr<DownloadedResource>, boost::shared_ptr<Downloader>> Downloader::downloaders;

Downloader::Downloader(boost::shared_ptr<DownloadedResource> downloadedResource) :
    downloadedResource(downloadedResource)
{
    downloaders.insert(
            std::pair<boost::shared_ptr<DownloadedResource>, boost::shared_ptr<Downloader>>
                     (downloadedResource, boost::shared_ptr<Downloader>(this)));
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