#ifndef GAME_OVER_SYSTEM_H
#define GAME_OVER_SYSTEM_H

#include "System/system.h"

class GameOverSystem : public System
{
public:
    void update(double deltaTime) override;
};

#endif