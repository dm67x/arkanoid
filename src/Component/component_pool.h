#ifndef COMPONENT_POOL_H
#define COMPONENT_POOL_H

#include <map>
#include <memory>
#include <string>
#include "component.h"
#include "singleton.h"

class ComponentPool : public Singleton<ComponentPool>
{

private:
    std::map<std::string, std::shared_ptr<Component>> components;

public:
    ComponentPool();
    ~ComponentPool();

    void add(std::string id, std::shared_ptr<Component> c);
    std::shared_ptr<Component> get(std::string id);

};

#endif
