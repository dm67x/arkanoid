#ifndef COMPONENT_GRAPHIC_H
#define COMPONENT_GRAPHIC_H

#include <SDL.h>
#include <string>
#include "Component/component.h"

namespace Components
{


class Graphic : public Component
{

private:
    SDL_Surface * graphic;
    SDL_Rect cut;

public:
    Graphic();
    Graphic(std::string filename);
    Graphic(std::string filename, SDL_Rect rect);
    ~Graphic();

    void fromFile(std::string filename);
    void fromSprite(std::string filename, SDL_Rect rect);
    SDL_Surface * getSurface();
    SDL_Rect getCut();

    std::string getName();

};

}

#endif
