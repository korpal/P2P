#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

#include <string>


class Configuration
{
    public:
        static const int PART_SIZE = 1*1024;
        static const int PARTS_TIMEOUT_IN_SECONDS = 5;
        static const int MAX_FILE_NAME_LENGTH = 128;
        static const int BROADCAST_PORT = 8887;
        static const int UNICAST_PORT = 8888;
};

#endif
