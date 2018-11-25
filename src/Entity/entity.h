/**
  * @file entity.h
  * @version 1
  */

#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <map>
#include "Component/component.h"

/**
 * @brief La classe entité (mère de toutes les autres classes entités)
 */
class Entity
{

private:
    std::string name;
    std::map<std::string, Component *> components;

protected:
    Entity(std::string name);

public:
    virtual ~Entity();

    std::string getName();
    std::map<std::string, Component *> getComponents();
    void addComponent(Component * c);
    void removeComponent(std::string name);
    Component * findComponent(std::string name);

    //bool collideWith(Entity & e);

};

#endif // ENTITY_H
