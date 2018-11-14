#include "graphic.h"

using namespace Components;

Graphic::Graphic() {
    graphic = nullptr;
}

Graphic::Graphic(std::string filename) {
    graphic = SDL_LoadBMP(filename.c_str());
    cut = { -1, -1, -1, -1 };
}

Graphic::Graphic(std::string filename, SDL_Rect rect) {
    graphic = SDL_LoadBMP(filename.c_str());
    cut = rect;
}

Graphic::~Graphic() {
    delete graphic;
}

void Graphic::fromFile(std::string filename) {
    graphic = SDL_LoadBMP(filename.c_str());
}

void Graphic::fromSprite(std::string filename, SDL_Rect rect) {
    graphic = SDL_LoadBMP(filename.c_str());
    cut = rect;
}

SDL_Surface * Graphic::getSurface() {
    return graphic;
}

SDL_Rect Graphic::getCut() {
    return cut;
}

std::string Graphic::getName() {
    return "graphic";
}
