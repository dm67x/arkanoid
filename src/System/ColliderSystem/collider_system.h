#ifndef COLLIDER_SYSTEM_H
#define COLLIDER_SYSTEM_H

#include "System/system.h"

class ColliderSystem : public System
{
public:
    void update(float deltaTime) override;
};

#endif