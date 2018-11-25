#include "graphic.h"

using namespace Components;

Graphic::Graphic(SDL_Rect src) : Component("graphic"), src(src) {
}

Graphic::~Graphic() {
}

void Graphic::setRect(SDL_Rect src) {
    this->src = src;
}

SDL_Rect Graphic::getRect() {
    return src;
}