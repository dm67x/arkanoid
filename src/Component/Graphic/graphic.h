#ifndef COMPONENT_GRAPHIC_H
#define COMPONENT_GRAPHIC_H

#include "Component/component.h"
#include <SDL.h>

namespace Components
{
    class Graphic : public Component 
    {
    private:
        SDL_Rect src;

    public:
        Graphic(SDL_Rect src);
        ~Graphic() override;

        SDL_Rect getRect();
        void setRect(SDL_Rect src);
    };
}

#endif // COMPONENT_GRAPHIC_H