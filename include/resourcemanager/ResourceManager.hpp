#ifndef RESOURCE_MANAGER
#define RESOURCE_MANAGER

#include <bits/unordered_map.h>
#include <boost/smart_ptr/shared_ptr.hpp>
#include "LocalResource.hpp"
#include "RemoteResource.hpp"
#include <mutex>

class ResourceManager
{
public:
    ResourceManager();

    // Adds a local source stored at given path
    void addLocal(const std::string &path);

    // Adds a remote source

private:
    std::map<unsigned int, boost::shared_ptr<LocalResource>> localData;
    std::map<unsigned int, boost::shared_ptr<RemoteResource>> remoteData;

    mutex mutex;
};

#endif RESOURCE_MANAGER