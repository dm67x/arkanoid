#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <memory>
#include <vector>
#include "Component/component.h"
#include "Component/component_pool.h"

class Entity
{

private:
    std::string name;
    std::string type;
    std::vector<std::shared_ptr<Component>> components;
    static ComponentPool * components_pool;

protected:
    Entity(std::string name, std::string type);

public:
    virtual ~Entity();

    void add(std::shared_ptr<Component> component);
    void remove(std::shared_ptr<Component> component);
    std::vector<std::shared_ptr<Component>> getComponents();
    std::shared_ptr<Component> findComponent(std::string type);

};

#endif
