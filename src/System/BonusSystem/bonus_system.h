#ifndef BONUS_SYSTEM_H
#define BONUS_SYSTEM_H

#include "System/system.h"

class BonusSystem : public System
{
public:
    void update(double deltaTime) override;
};

#endif