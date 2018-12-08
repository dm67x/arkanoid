#include "ball.h"

using namespace Entities;

Ball::Ball() : DynamicEntity("ball") {
    setGraphic({ 80, 64, 16, 16 });
    setDirection(Vector2<float>(0, 0));
    setSpeed(5.0f);
	setMovable(false);

    event_manager->attach("launch_ball", [this](void *) {
		if (!this->canMove()) {
			this->setMovable(true);
			if (this->getDirection().y == 0)
				this->setDirection(Vector2<float>(0, -1));
		}
    });

	event_manager->attach("move_ball_before_launch", [this](void * p) {
		if (this->canMove()) return;
		SDL_Event * e = (SDL_Event *)p;
		this->setPosition(Vector2<float>(static_cast<float>(e->motion.x), this->getPosition().y));
	});
}

Ball::~Ball() {
}

std::string Ball::getType() {
    return "ball";
}