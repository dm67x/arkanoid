#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>

class Component
{
private:
    std::string name;

protected:
    Component(std::string name);
    
public:
    virtual ~Component();

    std::string getName();
};

#endif // COMPONENT_H