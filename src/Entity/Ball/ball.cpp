/**
 * @file ball.cpp
 * @version 1
 */

#include "ball.h"
#include "Component/Graphic/graphic.h"
#include "Component/Position/position.h"

using namespace Entities;

Ball::Ball() : Entity("ball") {
    addComponent(new Components::Graphic({ 80, 64, 16, 16 }));
    addComponent(new Components::Position());
}

Ball::~Ball() {
}

/*void Ball::update(double dt) {
    Vector2<int> position = getPosition();
    Vector2<int> dir = _direction * static_cast<int>(_speed);
    position = position + dir;
    setPosition(position);
}*/
