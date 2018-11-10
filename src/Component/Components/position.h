#ifndef COMPONENT_POSITION_H
#define COMPONENT_POSITION_H

#include "Component/component.h"
#include <SDL.h>

namespace Components
{

class Position : public Component
{

private:
    SDL_Rect position;

public:
    Position();
    Position(int x, int y);
    ~Position();

    void set(int x, int y);
    SDL_Rect get();

    std::string getName();

};

}

#endif
