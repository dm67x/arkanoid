/**
 * @file ball.cpp
 * @version 1
 */

#include "ball.h"

using namespace Entities;

Ball::Ball() : Entity("ball"), _speed(5), _direction(Vector2<int>(0, 1)) {
    setPosition(Vector2<int>(100, 100));
    _src_rect = { 80, 64, 16, 16 };
}

Ball::~Ball() {
}

/*void Ball::update(double dt) {
    Vector2<int> position = getPosition();
    Vector2<int> dir = _direction * static_cast<int>(_speed);
    position = position + dir;
    setPosition(position);
}*/

void Ball::setDirection(Vector2<int> direction) {
    _direction = direction;
}
