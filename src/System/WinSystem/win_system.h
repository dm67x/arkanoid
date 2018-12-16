#ifndef WIN_SYSTEM_H
#define WIN_SYSTEM_H

#include "System/system.h"

class WinSystem : public System
{
public:
    void update(double deltaTime) override;
};

#endif