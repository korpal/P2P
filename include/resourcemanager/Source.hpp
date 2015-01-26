#ifndef SOURCE
#define SOURCE

#include <netinet/in.h>
#include <iostream>

class Source
{
    public:
        Source(char* address);
        std::string getAddress();
    private:
        char address[14];
};

#endif // SOURCE