#include "collision.h"
#include "Entity/Ball/ball.h"

using namespace Systems;

Collision::Collision() {
}

Collision::~Collision() {
}

void Collision::update(double dt) {
	/*Entities::Ball * ball = nullptr;

	for (auto e : _entity_factory->getEntities()) {
		if (e->getName() == "ball")
			ball = dynamic_cast<Entities::Ball *>(e);
	}

	if (!ball) return;

	for (auto e : _entity_factory->getEntities()) {
		if (e->getName() == "ball") continue;
		if (e->collideWith(*ball)) {
			ball->setDirection(Vector2<int>(1, -1));
		}
	}*/
}

void Collision::draw(SDL_Surface & surface) {

}