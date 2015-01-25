#ifndef RESOURCE_MANAGER
#define RESOURCE_MANAGER

#include <boost/smart_ptr/shared_ptr.hpp>
#include "LocalResource.hpp"
#include "RemoteResource.hpp"
#include <map>
#include <mutex>

class ResourceManager
{
public:
    ResourceManager();

    // Adds a local source stored at given path
    void addLocal(const std::string &path);

    // Adds a new Source to given RemoteResource, if it does not exist it is created
    void addRemote(const ResourceIdentifier& identifier, const Source& source);


private:
    std::map<unsigned int, boost::shared_ptr<LocalResource>> localData;
    std::map<unsigned int, boost::shared_ptr<RemoteResource>> remoteData;

    Lock mutex;
};

#endif // RESOURCE_MANAGER