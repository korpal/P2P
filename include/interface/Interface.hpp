#ifndef INTERFACE_H
#define INTERFACE_H

#include <map>
#include <vector>
#include <boost/smart_ptr/shared_ptr.hpp>
#include "../resourcemanager/ResourceIdentifier.hpp"

class Interface
{
public:
    Interface();

    void menu();
    void start();

private:
    std::map<unsigned int, void (Interface::*)()> options;
    typedef void (*methodPointer)(void);

    bool isFinished;
    void welcomingText();

    void addOptions();
    void addSingleOption(unsigned id, methodPointer method);

    // Options
    void enlistLocalResources();
        void addLocalResource();
        void revokeResource();

    void enlistRemoteResources();
        void downloadResorce();

    void enlistRevokedResources();
        void revertResource();

        void back();

    void stop();
};

#endif // INTERFACE_H