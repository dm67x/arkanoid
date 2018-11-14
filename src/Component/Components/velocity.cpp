#include "velocity.h"

using namespace Components;

Velocity::Velocity(int directionX, int directionY) : Velocity(1, directionX, directionY) {
}

Velocity::Velocity(int speed, int directionX, int directionY) {
    this->speed = speed;
    this->directionX = directionX;
    this->directionY = directionY;
}

Velocity::~Velocity() {
}

SDL_Rect Velocity::getVelocity() {
    SDL_Rect r;
    r.x = this->speed * this->directionX;
    r.y = this->speed * this->directionY;
    return r;
}

std::string Velocity::getName() {
    return "Velocity";
}
