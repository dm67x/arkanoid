#ifndef STATIC_ENTITY_H
#define STATIC_ENTITY_H

#include "entity.h"

class StaticEntity : public Entity
{
protected:
    StaticEntity(const std::string name) : Entity(name) {}
    
public:
    virtual ~StaticEntity() {}
    virtual std::string getType() = 0;
    void move() override {}
    void setDirection(Vector2<int> direction) override {}
};

#endif