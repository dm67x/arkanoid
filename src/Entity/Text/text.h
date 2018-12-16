#ifndef TEXT_ENTITY_H
#define TEXT_ENTITY_H

#include "Entity/entity.h"
#include "Component/text.h"
#include <string>

namespace Entities
{
    class Text : public Entity
    {
    private:
        Components::Text * text_comp;

        Components::Sprite * spriteFromChar(char c);

    public:
        Text(std::string text);

        void setText(std::string text);
    };
}

#endif