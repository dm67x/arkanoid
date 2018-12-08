#include "ship.h"
#include "singleton.h"
#include "EventManager/event_manager.h"

Ship::Ship(Entity id, EntityPool * pool) 
	: id(id), pool(pool) 
{
	EventManager * event_manager = Singleton<EventManager>::getInstance();

	// Evenement permettant de bouger le navire avec la souris
	event_manager->attach("move_ship", [this](void * p) {
		SDL_Event * e = (SDL_Event *)p;
		for (auto comp : this->pool->getComponents(this->id)) {
			if (comp->getName() == "transform") {
				TransformComponent * tc = static_cast<TransformComponent *>(comp);
				tc->position.x = e->motion.x;
			}
		}
	});

	// Components
	transform = new TransformComponent(id);
	render = new RenderComponent(id, { 385, 192, 98, 16 });
	movement = new MovementComponent(id);
	collision = new CollisionComponent(id, transform, render);
	movement->is_static = true;

	pool->add(id, *transform);
	pool->add(id, *render);
	pool->add(id, *movement);
	pool->add(id, *collision);
}

Ship::~Ship() {
	Singleton<EventManager>::getInstance()->detach("move_ship");

	pool->remove(id, *transform);
	pool->remove(id, *render);
	pool->remove(id, *movement);
	pool->remove(id, *collision);
}