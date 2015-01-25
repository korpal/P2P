//#include <bits/stl_map.h>
#include "../../include/resourcemanager/ResourceManager.hpp"
#include "../../include/utils/ScopedLock.hpp"
#include <stdio.h>
#include <iostream>
#include "RemoteResource.cpp"

ResourceManager::ResourceManager()
{

}

void ResourceManager::addLocal(const std::string &path)
{
    boost::shared_ptr<LocalResource> resource(new LocalResource(path));

    ScopedLock lock(mutex);

    unsigned id = resource->getResourceIdentifier().getID();

    if(localData.find(id) == localData.end())
        return;

    // TODO Invalidated wtf?

    localData.insert(std::pair<unsigned, boost::shared_ptr<LocalResource>>(id, resource)); // <unsigned, boost::shared_ptr<LocalResource>>
    // TODO hasNew ??
}

void ResourceManager::addRemote(const ResourceIdentifier &identifier, const Source &source)
{
    ScopedLock lock(mutex);

    boost::shared_ptr<RemoteResource> resource = remoteData[identifier.getID()];

    if(!resource)
    {
        // TU jest coś nie tak.....
        resource = boost::shared_ptr<RemoteResource>(new RemoteResource(identifier));
    }

    boost::shared_ptr<RemoteResource> resource2 = remoteData[identifier.getID()] ;

    // sprawdza czy dalej wskazuje na NULL czy już na obiekt
    if(!resource2)
        std::printf("STEFAN");

    resource->addSource(source);
}

