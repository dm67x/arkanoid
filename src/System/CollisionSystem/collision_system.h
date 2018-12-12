#ifndef COLLISION_SYSTEM_H
#define COLLISION_SYSTEM_H

#include "System/system.h"

class CollisionSystem : public System
{
public:
    void update(float deltaTime) override;
};

#endif