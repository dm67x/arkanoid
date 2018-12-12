#ifndef CONTROL_SYSTEM_H
#define CONTROL_SYSTEM_H

#include "System/system.h"

class ControlSystem : public System
{
public:
    void input(SDL_Event e) override;
};

#endif