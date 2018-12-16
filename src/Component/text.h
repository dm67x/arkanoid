#ifndef TEXT_COMPONENT_H
#define TEXT_COMPONENT_H

#include "component.h"
#include "sprite.h"

namespace Components
{
    class Text : public Component
    {
    public:
        std::string text;
        std::vector<Components::Sprite *> sprites;

        std::string name() const override { return "text"; }
    };
}

#endif