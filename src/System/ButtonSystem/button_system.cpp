#include "button_system.h"
#include "Component/button.h"
#include "Component/transform.h"
#include "Component/text.h"

using namespace Components;

void ButtonSystem::input(SDL_Event e) {
    System::input(e);

    if (e.type == SDL_MOUSEBUTTONUP) {
        for (auto entity : entity_manager->get()) {
            Button * btn = entity->get<Button>("button");
            Transform * tc = entity->get<Transform>("transform");
            Text * text = entity->get<Text>("text");

            if (!btn || !tc || !text) continue;

            int mouseX = e.button.x, mouseY = e.button.y;
            int text_width = 0, text_height = 0;
            for (auto s : text->sprites) {
                text_width += s->src.w;
                text_height = s->src.h;
            }

            SDL_Rect box;
            box.x = tc->position.x;
            box.y = tc->position.y;
            box.w = tc->position.x + text_width * tc->scale.x;
            box.h = tc->position.y + text_height * tc->scale.y;

            if (mouseX >= box.x && mouseX <= box.w && mouseY >= box.y && mouseY <= box.h) {
                // Souris sur le bouton
                event_manager->trigger(btn->action, nullptr);
            }
        }
    }
}