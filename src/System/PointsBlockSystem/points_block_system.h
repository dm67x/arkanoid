#ifndef POINTS_BLOCK_SYSTEM_H
#define POINTS_BLOCK_SYSTEM_H

#include "System/system.h"

class PointsBlockSystem : public System
{
private:
    SDL_Rect 
        cinquante, 
        soixante, 
        soixante_dix, 
        quatre_vingt, 
        quatre_vingt_dix, 
        cent, 
        cent_dix, 
        cent_vingt;

public:
    PointsBlockSystem();
    void update(double deltaTime) override;
};

#endif