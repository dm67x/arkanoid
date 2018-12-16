#ifndef TEXT_SYSTEM_H
#define TEXT_SYSTEM_H

#include "System/system.h"

class TextSystem : public System
{
private:
    SDL_Surface & sprite;

public:
    TextSystem(SDL_Surface & sprite);
    void draw(SDL_Surface & surface) override;
};

#endif