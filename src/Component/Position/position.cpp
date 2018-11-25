#include "position.h"

using namespace Components;

Position::Position() : Position(Vector2<int>(0, 0)) {
}

Position::Position(Vector2<int> position) 
    : Component("position"), position(position) {
}

Position::~Position() {
}

void Position::setPosition(Vector2<int> position) {
    this->position = position;
}

Vector2<int> Position::getPosition() {
    return position;
}

void Position::moveTo(Vector2<int> direction, float speed) {
    position = position + direction * speed;
}

