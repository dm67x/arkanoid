#include "position.h"

using namespace Components;

Position::Position() : Position(0, 0) {
}

Position::Position(int x, int y) {
    position.x = x;
    position.y = y;
}

Position::~Position() {
}

void Position::set(int x, int y) {
    position.x = x;
    position.y = y;
}

SDL_Rect Position::get() {
    return position;
}

std::string Position::getName() {
    return "Position";
}
