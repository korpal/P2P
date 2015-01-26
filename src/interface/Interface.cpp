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
        (*this.*options[X-1])();
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

}

void Interface::enlistRemoteResources()
{

}

void Interface::enlistRevokedResources()
{

}

void Interface::stop()
{
    isFinished = true;
}











void Interface::addSingleOption(unsigned id, methodPointer method)
{
    //options.insert(std::pair<unsigned int, void (Interface::*)()>(id, *method));
}