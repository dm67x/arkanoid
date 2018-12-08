#include "text.h"
#include <cassert>

using namespace Entities;

Text::Text() : Text("") {
}

Text::Text(const std::string text) : StaticEntity("Text") {
	setText(text);
}

void Text::setText(const std::string text) {
	this->text = text;
}

std::vector<SDL_Rect> Text::getTextGraphics() {
	std::vector<SDL_Rect> graphics;
	for (char c : text) {
		graphics.push_back(getGraphicFromChar(c));
	}
	return graphics;
}

SDL_Rect Text::getGraphicFromChar(char c) {
	assert(c >= 32 && c <= 126);
	int charnum = c - 32;
	int x = charnum % 16;
	int y = charnum / 16;
	int width = 32;
	int height = 32;
	return { x * width, y * height, width, height };
}

std::string Text::getType() {
	return "text";
}