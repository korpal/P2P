#include "../../include/resourcemanager/ResourceManager.hpp"
#include "../../include/utils/ScopedLock.hpp"

ResourceManager::ResourceManager()
{

}

void ResourceManager::addLocalResource(const std::string &path)
{
    boost::shared_ptr<LocalResource> resource(new LocalResource(path));

    ScopedLock lock(mutex);

    unsigned id = resource->getResourceIdentifier().getID();

    if(localData.find(id) == localData.end())
        return;

    // TODO Invalidated wtf?
    localData.insert(std::pair<unsigned, boost::shared_ptr<LocalResource>>(id, resource));
    // TODO hasNew ??
}

void ResourceManager::addRemoteResource(const ResourceIdentifier &identifier, const Source &source)
{
    ScopedLock lock(mutex);

    boost::shared_ptr<RemoteResource> resource = remoteData[identifier.getID()];

    if(!resource)
    {
        resource = boost::shared_ptr<RemoteResource>(new RemoteResource(identifier));
        remoteData[identifier.getID()] = resource;
    }

    resource->addSource(source);
}

void ResourceManager::addDownloadedResource(const ResourceIdentifier &identifier)
{
    ScopedLock lock(mutex);

    boost::shared_ptr<DownloadedResource> resource = downloadedData[identifier.getID()];

    if(!resource)
    {
        resource = boost::shared_ptr<DownloadedResource>(new DownloadedResource(identifier));
        downloadedData[identifier.getID()] = resource;
    }
}

Part& ResourceManager::getPartForSending(const ResourceIdentifier &identifier,
        const unsigned &id)
{
    ScopedLock lock(mutex);

    std::map<unsigned int, boost::shared_ptr<LocalResource>>::iterator iter =
            localData.find(identifier.getID());

    assert(iter != localData.end());

    return iter->second->getPart(id);
}