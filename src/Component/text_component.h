#ifndef TEXT_COMPONENT_H
#define TEXT_COMPONENT_H

#include "component.h"

#include <SDL2/SDL.h>
#include <string>
#include <cassert>

class TextComponent : public Component
{
private:
	inline SDL_Rect getRectFromChar(char c) {
		assert(c >= 32 && c <= 126);
		int charnum = c - 32;
		int x = charnum % 16;
		int y = charnum / 16;
		int width = 32;
		int height = 32;
		return { x * width, y * height, width, height };
	}

public:
	TextComponent(std::string text) 
		: Component(), text(text) {}

	std::string text;
	
	inline std::vector<SDL_Rect> getRects() {
		std::vector<SDL_Rect> graphics;
		for (char c : text) {
			graphics.push_back(getRectFromChar(c));
		}
		return graphics;
	}

	std::string getName() override { return "text"; }
};

#endif