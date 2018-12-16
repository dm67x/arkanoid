#ifndef BUTTON_ENTITY_H
#define BUTTON_ENTITY_H

#include "Entity/entity.h"
#include "Entity/Text/text.h"

namespace Entities
{
    class Button : public Entity
    {
    private:
        Components::Sprite * spriteFromChar(char c);

    public:
        Button(std::string text, std::string action);
    };
}

#endif