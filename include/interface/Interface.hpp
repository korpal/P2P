#ifndef INTERFACE_H
#define INTERFACE_H

#include <map>

class Interface
{
public:
    Interface();

    void menu();

private:
    std::map<unsigned int, void (Interface::*)()> options;
    typedef void (*methodPointer)(void);

    void welcomingText();

    void addOptions();
    void addSingleOption(unsigned id, methodPointer method);

    // Options
    void addLocalResource(){};
};

#endif // INTERFACE_H