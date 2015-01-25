#ifndef SOURCE
#define SOURCE

#include <netinet/in.h>

class Source
{
public:
    Source(const struct sockaddr_in& address);

private:
    struct sockaddr_in address;
};

#endif // SOURCE