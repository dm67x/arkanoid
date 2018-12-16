#ifndef BUTTON_SYSTEM_H
#define BUTTON_SYSTEM_H

#include "System/system.h"

class ButtonSystem : public System
{
public:
    void input(SDL_Event e) override;
};

#endif