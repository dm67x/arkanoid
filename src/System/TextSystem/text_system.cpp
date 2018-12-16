#include "text_system.h"
#include "Component/text.h"
#include "Component/transform.h"

TextSystem::TextSystem(SDL_Surface & sprite) : sprite(sprite) {
}

void TextSystem::draw(SDL_Surface & surface) {
    for (auto entity : entity_manager->get()) {
        Components::Text * text = entity->get<Components::Text>("text");
        Components::Transform * tc = entity->get<Components::Transform>("transform");
        if (!text || !tc) continue;
        int i = 0;
        for (auto sp : text->sprites) {
            SDL_Rect dest = { 
                static_cast<int>((sp->src.w * tc->scale.x / 2) * i + tc->position.x / 2),
                static_cast<int>(tc->position.y) / 2, 
                sp->src.w * tc->scale.x, sp->src.h * tc->scale.y 
            };
            i++;
            SDL_BlitScaled(&sprite, &sp->src, &surface, &dest);
        }
    }
}