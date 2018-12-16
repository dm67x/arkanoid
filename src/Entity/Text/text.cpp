#include "text.h"
#include "Component/transform.h"
#include <cassert>

using namespace Entities;

Text::Text(std::string text) {
    text_comp = new Components::Text();
    text_comp->text = text;
    
    for (auto c : text) {
        Components::Sprite * s = spriteFromChar(c);
        text_comp->sprites.push_back(s);
    }

    add(text_comp);
    add(new Components::Transform());
}

Components::Sprite * Text::spriteFromChar(char c) {
    assert(c >= 32 && c <= 126);
	int charnum = c - 32;
	int x = charnum % 16;
	int y = charnum / 16;
	int width = 32;
	int height = 32;
	SDL_Rect rect = { x * width, y * height, width, height };
    Components::Sprite * s = new Components::Sprite();
    s->src = rect;
}

void Text::setText(std::string text) {
    text_comp->text = text;
    text_comp->sprites.clear();
    for (auto c : text) {
        Components::Sprite * s = spriteFromChar(c);
        text_comp->sprites.push_back(s);
    }
}