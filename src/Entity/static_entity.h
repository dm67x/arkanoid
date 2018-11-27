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
    inline void setDirection(Vector2<float> direction) override {}
    inline Vector2<float> getDirection() const override { return Vector2<float>(0, 0); }
};

#endif