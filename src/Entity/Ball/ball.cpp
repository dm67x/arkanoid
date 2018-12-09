#include "ball.h"
#include "singleton.h"
#include "EventManager/event_manager.h"

Ball::Ball(Entity id, EntityPool * pool)
	: id(id), pool(pool) 
{
	EventManager * event_manager = Singleton<EventManager>::getInstance();

	// Evenement permettant de bouger la balle en fonction du navire (avant le commencement)
	event_manager->attach("move_ball_with_ship", [this](void * p) {
		SDL_Event * e = (SDL_Event *)p;
		TransformComponent * tc = nullptr;
		MovementComponent * mc = nullptr;

		for (auto comp : this->pool->getComponents(this->id)) {
			if (comp->getName() == "transform") {
				tc = static_cast<TransformComponent *>(comp);
			}
			else if (comp->getName() == "movement") {
				mc = static_cast<MovementComponent *>(comp);
			}
		}

		if (tc && mc) {
			if (mc->is_static)
				tc->position.x = static_cast<float>(e->motion.x);
		}
	});

	// Evenement permettant de lancer une balle
	event_manager->attach("launch_ball", [this](void *) {
		MovementComponent * mc = nullptr;

		for (auto comp : this->pool->getComponents(this->id)) {
			if (comp->getName() == "movement") {
				mc = static_cast<MovementComponent *>(comp);
			}
		}

		if (mc) {
			if (mc->is_static) {
				mc->is_static = false;
				mc->direction = Vector2<float>(0, -1);
			}
		}
	});

	// Components
	transform = new TransformComponent(id);
	render = new RenderComponent(id, { 80, 64, 16, 16 });
	movement = new MovementComponent(id, 5.0f, Vector2<float>(0, -1), true);
	collision = new CollisionComponent(id, transform, render);
	collision->q = 2;
	type = new TypeComponent(id, "ball");

	pool->add(id, *transform);
	pool->add(id, *render);
	pool->add(id, *movement);
	pool->add(id, *collision);
	pool->add(id, *type);
}

Ball::~Ball() {
	Singleton<EventManager>::getInstance()->detach("launch_ball");
	Singleton<EventManager>::getInstance()->detach("move_ball_with_ship");

	pool->remove(id, *transform);
	pool->remove(id, *render);
	pool->remove(id, *movement);
	pool->remove(id, *collision);
	pool->remove(id, *type);
}