#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <vector>

#include "Component/component.h"

class Entity
{
private:
    static unsigned int next_id;
    unsigned int id;
    std::vector<Component *> components;
    bool active;

public:
    Entity();
    virtual ~Entity();

    void add(Component * c);
    void remove(std::string name);

    template<typename T>
    T * get(std::string name) {
        for (auto it = components.begin(); it != components.end(); it++) {
            if ((*it)->name() == name) {
                return static_cast<T *>(*it);
            }
        }
        return nullptr;
    }

    inline std::vector<Component *> getComponents() { return components; }
    inline const unsigned int getID() { return id; }
    virtual void setActive(bool active);
    inline const bool isActive() { return active; }
};

#endif