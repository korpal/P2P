#include <iostream>
#include "../../include/interface/Interface.hpp"
#include "../../include/resourcemanager/ResourceManager.hpp"

using namespace std;

inline void Q(string X)
{
    cout << X << endl;
}

Interface::Interface() :
    isFinished(false)
{
    addOptions();
}

void Interface::start()
{
    welcomingText();
    while(!isFinished)
    {
        menu();
        int X = getchar() - '0';
        while (X == 0 || X > options.size())
        {
            Q("Błędna decyzja!");
            X = getchar() - '0';
        }
        (*this.*options[X])();
    }
}

void Interface::welcomingText()
{
     Q("Welcome to RR Torrent!");
}

void Interface::menu()
{
    Q("");
    Q("Menu:");
    Q("1. Enlist local resources.");
    Q("2. Enlist remote reources.");
    Q("3. Enlist revoked reources.");
    Q("4. Xit.");
}

void Interface::addOptions()
{
    //addSingleOption(1, &Interface::addLocalResource);
    options.insert(make_pair(1, &Interface::enlistLocalResources));
    options.insert(make_pair(2, &Interface::enlistRemoteResources));
    options.insert(make_pair(3, &Interface::enlistRevokedResources));


    options.insert(make_pair(4, &Interface::stop));
}

void Interface::enlistLocalResources()
{
    options.clear();
    Q("");
    Q("Local Resources:");
    vector<ResourceIdentifier> resources = ResourceManager::getInstance().getLocalResourcesInfo();
    int i;
    std::string str;
    for(i = 0; i < resources.size(); i++)
    {
        str.append((char const *)i-48);
        str.append(". " + resources[i].getName());
        Q(str);
        str.clear();
        options.insert(make_pair(i, &Interface::addLocalResource));
    }
    str.append((char const *)i-48);
    str.append(". Exit.");
    options.insert(make_pair(i, &Interface::back));
    Q(str);
    delete str;
}

void Interface::enlistRemoteResources()
{
    options.clear();
    Q("");
    Q("Remote Resources:");
    vector<ResourceIdentifier> resources = ResourceManager::getInstance().getRemoteResourcesInfo();
    int i;
    std::string str;
    for(i = 0; i < resources.size(); i++)
    {
        str.append((char const *)i-48);
        str.append(". " + resources[i].getName());
        Q(str);
        str.clear();
        options.insert(make_pair(i, &Interface::downloadResource));
    }
    str.append((char const *)i-48);
    str.append(". Exit.");
    options.insert(make_pair(i, &Interface::back));
    Q(str);
    delete str;
}

void Interface::enlistRevokedResources()
{
    options.clear();
    Q("");
    Q("Revoked Resources:");
    vector<ResourceIdentifier> resources = ResourceManager::getInstance().getRevokedResourcesInfo();
    int i;
    std::string str;
    for(i = 0; i < resources.size(); i++)
    {
        str.append((char const *)i-48);
        str.append(". " + resources[i].getName());
        Q(str);
        str.clear();
        options.insert(make_pair(i, &Interface::revertResource));
    }
    str.append((char const *)i-48);
    str.append(". Exit.");
    options.insert(make_pair(i, &Interface::back));
    Q(str);
    delete str;
}

void Interface::stop()
{
    isFinished = true;
}



void Interface::addSingleOption(unsigned id, methodPointer method)
{
    //options.insert(std::pair<unsigned int, void (Interface::*)()>(id, *method));
}

void Interface::addLocalResource()
{

}

void Interface::revokeResource()
{

}

void Interface::downloadResource()
{

}

void Interface::revertResource()
{

}
