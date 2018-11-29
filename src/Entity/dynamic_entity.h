#ifndef DYNAMIC_ENTITY_H
#define DYNAMIC_ENTITY_H

#include "entity.h"

class DynamicEntity : public Entity
{
private:
    float speed;
    Vector2<float> direction;

protected:
    DynamicEntity(const std::string name) : Entity(name) {}

public:
    virtual ~DynamicEntity() {}
    virtual std::string getType() = 0;
    void move() override;
    void setDirection(Vector2<float> direction) override;

    inline void setSpeed(float s) { speed = s; }
    inline float getSpeed() const { return speed; }
    inline Vector2<float> getDirection() const override { return direction; }
};

#endif