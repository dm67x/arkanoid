#include "button.h"
#include "Component/button.h"
#include "Component/transform.h"
#include "Component/text.h"
#include <cassert>

using namespace Entities;

Button::Button(std::string text, std::string action) {
    Components::Button * btn = new Components::Button();
    btn->action = action;
    add(btn);

    add(new Components::Transform());
    Components::Text * tc = new Components::Text();
    tc->text = text;
    for (auto t : text) {
        tc->sprites.push_back(spriteFromChar(t));
    }
    add(tc);
}

Components::Sprite * Button::spriteFromChar(char c) {
    assert(c >= 32 && c <= 126);
	int charnum = c - 32;
	int x = charnum % 16;
	int y = charnum / 16;
	int width = 32;
	int height = 32;
	SDL_Rect rect = { x * width, y * height, width, height };
    Components::Sprite * s = new Components::Sprite();
    s->src = rect;
    return s;
}