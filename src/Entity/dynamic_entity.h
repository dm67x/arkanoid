#ifndef DYNAMIC_ENTITY_H
#define DYNAMIC_ENTITY_H

#include "entity.h"

class DynamicEntity : public Entity
{
private:
    float speed;

protected:
    DynamicEntity(const std::string name) : Entity(name) {}

public:
    virtual ~DynamicEntity() {}
    virtual std::string getType() = 0;

    inline void setSpeed(float s) { speed = s; }
    inline float getSpeed() const { return speed; }
};

#endif