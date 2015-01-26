#ifndef REMOTE_RESOURCE
#define REMOTE_RESOURCE

#include "ResourceIdentifier.hpp"
#include "Source.hpp"

class RemoteResource
{
public:
    RemoteResource(const ResourceIdentifier &resourceIdentifier);

    void addSource(const Source& source);
    const std::vector<Source> getSources() const;
    ResourceIdentifier& getResourceIdentifier();

private:
    std::vector<Source> sources;
    ResourceIdentifier resourceIdentifier;
};

#endif // REMOTE_RESOURCE