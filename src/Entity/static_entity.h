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
    inline void move() override {}
    inline void setDirection(Vector2<int> direction) override {}
    inline Vector2<int> getDirection() const override { return Vector2<int>(0, 0); }
};

#endif