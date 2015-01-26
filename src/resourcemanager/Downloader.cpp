#include "../../include/resourcemanager/Downloader.hpp"
#include "../../include/resourcemanager/ResourceManager.hpp"
#include "../../include/utils/EventQueue.hpp"

std::map<boost::shared_ptr<DownloadedResource>, boost::shared_ptr<Downloader>> Downloader::downloaders;

Downloader::Downloader(boost::shared_ptr<DownloadedResource> downloadedResource) :
    downloadedResource(downloadedResource)
{
    downloaders.insert(
            std::pair<boost::shared_ptr<DownloadedResource>, boost::shared_ptr<Downloader>>
                     (downloadedResource, boost::shared_ptr<Downloader>(this)));
    sources = ResourceManager::getInstance().getSources(downloadedResource->getResourceIdentifier());
    for(int i = 0; i < sources.size(); i++)
        sourcesQueue.push(sources[i]);
}

void Downloader::run()
{
    while(!isFinished())
    {
        try
        {
            // Take source from queue
            Source source = sourcesQueue.pop(Configuration::PARTS_TIMEOUT_IN_SECONDS);
            int partId = downloadedResource->getIdOfPartForDownloading();
            // If all parts are downloaded
            if(partId < 0)
                break;

            EventQueue::getInstance().push(new OutgoingPartRequestEvent(downloadedResource->getResourceIdentifier(), partId, source));
        }
        catch(...)
        {
            for(int i = 0; i < sources.size(); i++)
                sourcesQueue.push(sources[i]);
        }
    }
}

void Downloader::notifyAboutSource(Source &source)
{
    sourcesQueue.push(source);
}
