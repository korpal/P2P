#ifndef REMOTE_RESOURCE
#define REMOTE_RESOURCE

#include "ResourceIdentifier.hpp"
#include "Source.hpp"

class RemoteResource
{
public:
    RemoteResource(const ResourceIdentifier &resourceIdentifier);
    ~RemoteResource();

    void addSource(const Source& source);
    const std::vector<Source> getSources() const;

private:
    std::vector<Source> sources;
    ResourceIdentifier resourceIdentifier;
};

#endif // REMOTE_RESOURCE