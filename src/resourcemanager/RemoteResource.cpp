#include <bits/stl_bvector.h>
#include "../../include/resourcemanager/RemoteResource.hpp"

RemoteResource::RemoteResource(const ResourceIdentifier &resourceIdentifier) :
    resourceIdentifier(resourceIdentifier)
{

}

void RemoteResource::addSource(const Source &source)
{
    sources.push_back(source);
}

const std::vector<Source> RemoteResource::getSources() const
{
    return sources;
}