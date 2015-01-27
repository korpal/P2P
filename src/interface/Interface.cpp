#include <iostream>
#include <istream>
#include <sstream>
#include "../../include/interface/Interface.hpp"
#include "../../include/resourcemanager/ResourceManager.hpp"
#include "../../include/controller/Events.hpp"
#include "../../include/utils/EventQueue.hpp"

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
    menu();
    char c;
    while(!isFinished)
    {
        cin >> c;
        chosen = c - '0';
        while (chosen == 0 || chosen > options.size())
        {
            Q("Błędna decyzja!");
            cin >> c;
            chosen = c - '0';
        }
        (*this.*options[chosen])();
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
    Q("2. Enlist remote resources.");
    Q("3. Enlist revoked resources.");
    Q("4. Enlist downloaded resources.");
    Q("5. Xit.");
}

void Interface::addOptions()
{
    //addSingleOption(1, &Interface::addLocalResource);
    options.insert(make_pair(1, &Interface::enlistLocalResources));
    options.insert(make_pair(2, &Interface::enlistRemoteResources));
    options.insert(make_pair(3, &Interface::enlistRevokedResources));
    options.insert(make_pair(4, &Interface::enlistDownloadingResources));
    options.insert(make_pair(5, &Interface::stop));
}

void Interface::enlistLocalResources()
{
    options.clear();
    Q("");
    Q("Local Resources:");
    vector<ResourceIdentifier> resources = ResourceManager::getInstance().getLocalResourcesInfo();
    int i;
    std::string str;
    for(i = 1; i <= resources.size(); i++)
    {
        str += i+48;
        str.append(". " + resources[i-1].getName());
        Q(str);
        str.clear();
        options.insert(make_pair(i, &Interface::revokeResource));
    }
    str += i+48;
    str.append(". Add new local resource.");
    options.insert(make_pair(i, &Interface::addLocalResource));
    Q(str);
    str.clear();
    i++;
    str += i+48;
    str.append(". Back.");
    options.insert(make_pair(i, &Interface::back));
    Q(str);
}

void Interface::enlistRemoteResources()
{
    options.clear();
    Q("");
    Q("Remote Resources:");
    vector<ResourceIdentifier> resources = ResourceManager::getInstance().getRemoteResourcesInfo();
    int i;
    std::string str;
    for(i = 1; i <= resources.size(); i++)
    {
        str += i+48;
        str.append(". " + resources[i-1].getName());
        Q(str);
        str.clear();
        options.insert(make_pair(i, &Interface::downloadResource));
    }
    str += i+48;
    str.append(". Download all resources.");
    options.insert(make_pair(i, &Interface::downloadAllResources));
    Q(str);
    str.clear();
    i++;
    str += i+48;
    str.append(". Back.");
    options.insert(make_pair(i, &Interface::back));
    Q(str);
}

void Interface::enlistRevokedResources()
{
    options.clear();
    Q("");
    Q("Revoked Resources:");
    vector<ResourceIdentifier> resources = ResourceManager::getInstance().getRevokedResourcesInfo();
    int i;
    std::string str;
    for(i = 1; i <= resources.size(); i++)
    {
        str += i+48;
        str.append(". " + resources[i-1].getName());
        Q(str);
        str.clear();
        options.insert(make_pair(i, &Interface::revertResource));
    }
    str += i+48;
    str.append(". Back.");
    options.insert(make_pair(i, &Interface::back));
    Q(str);
}


void Interface::enlistDownloadingResources()
{
    options.clear();
    Q("");
    Q("Downloading progress:");
    std::vector<std::pair<std::string, double>> resources =
            ResourceManager::getInstance().getProgressInfo();
    int i;
    std::string str;
    for(i = 1; i <= resources.size(); i++)
    {
        ostringstream ss;
        ss << (int)resources[i-1].second;
        str = ss.str() + "% " + resources[i-1].first;
        Q(str);
    }
    str.clear();
    str.append("1 Back.");
    options.insert(make_pair(1, &Interface::back));
    Q(str);
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
    string path;
    Q("Type file path:");
    cin >> path;
//    EventQueue::getInstance().push(new NewLocalResourceEvent(*(new string(path))));
    ResourceManager::getInstance().addLocalResource(*(new string(path)));
    back();
}

void Interface::revokeResource()
{
    vector<ResourceIdentifier> resources = ResourceManager::getInstance().getLocalResourcesInfo();
    ResourceIdentifier ri = resources[chosen-1];
    EventQueue::getInstance().push(new OutgoingRevokeRequestEvent(*(new ResourceIdentifier(ri.getName(), ri.getSize()))));
    ResourceManager::getInstance().revokeResource(
            *(new ResourceIdentifier(ri.getName(), ri.getSize())));
    back();
}


void Interface::downloadAllResources()
{
    EventQueue::getInstance().push(new OutgoingAllResourcesRequestEvent());
    back();
}


void Interface::downloadResource()
{
    vector<ResourceIdentifier> resources = ResourceManager::getInstance().getRemoteResourcesInfo();
    ResourceIdentifier ri = resources[chosen-1];
//    EventQueue::getInstance().push(new NewDownloadedResourceEvent(*(new ResourceIdentifier(ri.getName(), ri.getSize()))));
    ResourceManager::getInstance().addDownloadedResource(
            *(new ResourceIdentifier(ri.getName(), ri.getSize())));
    back();
}

void Interface::revertResource()
{
    vector<ResourceIdentifier> resources = ResourceManager::getInstance().getRevokedResourcesInfo();
    ResourceIdentifier ri = resources[chosen-1];
    EventQueue::getInstance().push(new OutgoingRevertRequestEvent(*(new ResourceIdentifier(ri.getName(), ri.getSize()))));
    ResourceManager::getInstance().revertResource(
            *(new ResourceIdentifier(ri.getName(), ri.getSize())));
    back();
}

void Interface::back() {
    options.clear();
    menu();
    addOptions();
}

