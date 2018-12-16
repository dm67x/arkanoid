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

        int i = 0, x, y, w, h;
        for (auto sp : text->sprites) {
            x = static_cast<int>(tc->position.x + sp->src.w * tc->scale.x * i);
            y = static_cast<int>(tc->position.y);
            w = static_cast<int>(sp->src.w * tc->scale.x);
            h = static_cast<int>(sp->src.h * tc->scale.y);

            SDL_Rect dest = { x, y, w, h };
            SDL_BlitScaled(&sprite, &sp->src, &surface, &dest);
            i++;
        }
    }
}