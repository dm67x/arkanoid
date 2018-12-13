#ifndef MOVEMENT_SYSTEM_H
#define MOVEMENT_SYSTEM_H

#include "System/system.h"

class MovementSystem : public System
{
public:
    void update(double deltaTime) override;
};

#endif