#include "../../include/resourcemanager/ResourceManager.hpp"
#include "../../include/utils/ScopedLock.hpp"

ResourceManager::ResourceManager() {}


ResourceManager& ResourceManager::getInstance()
{
    static ResourceManager resourceManager;
    return resourceManager;
}


void ResourceManager::addLocalResource(const std::string &path)
{
    boost::shared_ptr<LocalResource> resource(new LocalResource(path));

    ScopedLock lock(mutex);

    unsigned id = resource->getResourceIdentifier().getID();

    if(!existsLocal(id))
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
    if(existsLocal(identifier.getID()))
        return;

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

std::vector<ResourceIdentifier> ResourceManager::getLocalResourcesInfo()
{
    typedef boost::shared_ptr<LocalResource> PTR_LR;
    typedef std::pair<unsigned int, PTR_LR> PAIR;
    std::vector<ResourceIdentifier> resultVector;

    for(PAIR tmpPair : localData)
        resultVector.push_back(tmpPair.second->getResourceIdentifier());

    return resultVector;
}

std::vector<ResourceIdentifier> ResourceManager::getRemoteResourcesInfo()
{
    typedef boost::shared_ptr<RemoteResource> PTR_RR;
    typedef std::pair<unsigned int, PTR_RR> PAIR;
    std::vector<ResourceIdentifier> resultVector;

    for(PAIR tmpPair : remoteData)
        resultVector.push_back(tmpPair.second->getResourceIdentifier());

    return resultVector;
}

// TODO UNTRUSTED POINTERS
void ResourceManager::transformDownloadedIntoLocal(const ResourceIdentifier &identifier)
{
    addLocalResource(identifier.getName());
    downloadedData.erase(identifier.getID());
}

bool ResourceManager::existsLocal(const unsigned &id) const
{
    return localData.find(id) != localData.end();
}

void ResourceManager::receivePart(const Part &part)
{
    unsigned id = part.getResourceIdentifier().getID();

    if(downloadedData.find(id) == downloadedData.end())
        return;

    downloadedData[id]->addDownloadedPart(part);
}

