#include <iostream>
#include "../../include/interface/Interface.hpp"

using namespace std;

inline string  Q(string X)
{
    cout << X << endl;
}

Interface::Interface()
{
    welcomingText();
}

void Interface::welcomingText()
{
     Q("Welcome to RR Torrent!");
}

void Interface::menu()
{
    Q("");
    Q("Menu:");
    Q("1. Add a new resource.");
}

void Interface::addOptions()
{
    //addSingleOption(1, &Interface::addLocalResource);
    options.insert(make_pair(1, &Interface::addLocalResource));
}

void Interface::addSingleOption(unsigned id, methodPointer method)
{
    //options.insert(std::pair<unsigned int, void (Interface::*)()>(id, *method));
}