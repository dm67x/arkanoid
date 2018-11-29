#include "ball.h"

using namespace Entities;

Ball::Ball() : DynamicEntity("ball") {
    setGraphic({ 80, 64, 16, 16 });
    setDirection(Vector2<float>(0, 0));
    setSpeed(5.0f);

    event_manager->attach("launch_ball", [this](void *) {
        if (this->getDirection().y == 0)
            setDirection(Vector2<float>(0, -1));
    });
}

Ball::~Ball() {
}

std::string Ball::getType() {
    return "ball";
}