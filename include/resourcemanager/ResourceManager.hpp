#ifndef RESOURCE_MANAGER
#define RESOURCE_MANAGER

#include <boost/smart_ptr/shared_ptr.hpp>
#include "LocalResource.hpp"
#include "RemoteResource.hpp"
#include "../utils/Lock.hpp"
#include "DownloadedResource.hpp"
#include <map>
#include <mutex>
#include <vector>

class ResourceManager
{
public:
    static ResourceManager& getInstance();

    // Adds a local source stored at given path
    void addLocalResource(const std::string &path);

    // Adds a new Source to given RemoteResource, if it does not exist it is created
    void addRemoteResource(const ResourceIdentifier& identifier, const Source& source);

    // Begins download of a file and adds it to download list
    void addDownloadedResource(const ResourceIdentifier& identifier);

    // Returns a requested Part for Sending
    Part& getPartForSending(const ResourceIdentifier& identifier, const unsigned& id);

    // Returns a set of information about local resources
    std::vector<ResourceIdentifier> getLocalResourcesInfo();

    // Returns a set of information about remote resources
    std::vector<ResourceIdentifier> getRemoteResourcesInfo();

    // Transforms a DownloadedReosurce into a LocalResource
    void transformDownloadedIntoLocal(const ResourceIdentifier& identifier);

    // Does resource of given id exist locally
    bool existsLocal(const unsigned& id) const;

    // React upon received Part
    void receivePart(const Part& part);

    // Revokes the resource so it can not be downloaded
    void revokeResource(const ResourceIdentifier& identifier);

    // Reverts the revocation so it can be downloaded again
    void revertResource(const ResourceIdentifier& identifier);

    // Sends info about available local resources
    void handleAllResourcesRequest(Source &source);

    // Sends part to the source
    void handlePartRequest(const ResourceIdentifier& identifier, const unsigned& id, Source &source);

private:
    ResourceManager();
    ResourceManager(const ResourceManager&);
    static ResourceManager resourceManager;

    std::map<unsigned int, boost::shared_ptr<LocalResource>> localData;
    std::map<unsigned int, boost::shared_ptr<LocalResource>> revokedData;
    std::map<unsigned int, boost::shared_ptr<RemoteResource>> remoteData;
    std::map<unsigned int, boost::shared_ptr<DownloadedResource>> downloadedData;

    Lock mutex;
};

#endif // RESOURCE_MANAGER