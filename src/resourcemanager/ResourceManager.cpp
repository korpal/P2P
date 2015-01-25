#include <bits/stl_map.h>
#include "../../include/resourcemanager/ResourceManager.hpp"
#include "../../include/utils/ScopedLock.hpp"

ResourceManager::ResourceManager()
{

}

void ResourceManager::addLocal(const std::string &path)
{
    boost::shared_ptr<LocalResource> resource = new LocalResource(path);

    ScopedLock lock(mutex);

    unsigned id = resource->getResourceIdentifier().getID();

    // TODO koniecznie sprawdzać w remote? remoteData.find(id) == remoteData.end() ||
    if(localData.find(id) == localData.end())
        return;

    // TODO Invalidated wtf?

    localData.insert(std::Pair(id, resource)); // <unsigned, boost::shared_ptr<LocalResource>>
    // TODO hasNew ??
}

