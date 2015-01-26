#include "../../include/resourcemanager/Downloader.hpp"
#include "../../include/resourcemanager/ResourceManager.hpp"

std::map<boost::shared_ptr<DownloadedResource>, boost::shared_ptr<Downloader>> Downloader::downloaders;

Downloader::Downloader(boost::shared_ptr<DownloadedResource> downloadedResource) :
    downloadedResource(downloadedResource)
{
    downloaders.insert(
            std::pair<boost::shared_ptr<DownloadedResource>, boost::shared_ptr<Downloader>>
                     (downloadedResource, boost::shared_ptr<Downloader>(this)));
    std::vector sources = ResourceManager::getInstance().getSources(downloadedResource->)
    //for()
}

void Downloader::run()
{
    while(!isFinished())
    {
        int partId = downloadedResource->getIdOfPartForDownloading();

        // If all parts are downloaded
        if(partId < 0)
            break;


        // Get Sources
        //
    }
}

void Downloader::notifyAboutSource(Source &source)
{
    sourcesQueue.push(source);
}
