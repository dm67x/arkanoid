#include <iostream>
#include <algorithm>
#include <cmath>

#include "collider_system.h"
#include "Window/window.h"
#include "Component/collision_component.h"
#include "Component/movement_component.h"
#include "Component/hit_component.h"
#include "Component/type_component.h"

void ColliderSystem::update(float deltaTime) {
	if (!current_scene) return;

	SDL_Rect p1, p2;
	Vector2<float> direction, reflection, d;
	int dx = 0, dy = 0;

	EntityPool * pool = current_scene->getPool();
	CollisionComponent * cc1 = nullptr, *cc2 = nullptr;
	MovementComponent * mc = nullptr;
	HitComponent * hc = nullptr;
	TypeComponent * tc = nullptr;

	std::map<uint32_t, std::vector<Component *>> entities = pool->getEntities();

	for (auto ent : entities) {
		for (auto comp : ent.second) {
			if (comp->getName() == "type")
				tc = static_cast<TypeComponent *>(comp);
			else if (comp->getName() == "collision")
				cc1 = static_cast<CollisionComponent *>(comp);
			else if (comp->getName() == "movement")
				mc = static_cast<MovementComponent *>(comp);
		}

		if (!tc || !cc1 || !mc) continue; // si pas de composant de collision ou movement arreter
		if (tc->type != "ball") continue; // si ce n'est paas une balle

		for (auto entity : entities) {
			if (entity.first == ent.first) continue; // continuer si la meme entit�

			for (auto comp : entity.second) {
				if (comp->getName() == "collision") {
					cc2 = static_cast<CollisionComponent *>(comp);
				}
				else if (comp->getName() == "hit") {
					hc = static_cast<HitComponent *>(comp);
				}
			}

			if (!cc2) continue; // si pas de composant de collision continuer

			if (cc1->collide(*cc2)) { // si collision
				if (hc) { // si bricks
					if (hc->destructible) {
						hc->hit--;
						if (hc->hit <= 0) {
							event_manager->trigger("destroy_entity", (void *)&(entity.first));
						}
					}
				}

				p1 = cc1->getBoundingBox(); // balle
				p2 = cc2->getBoundingBox(); // autre

				//SDL_Log("x: %i y: %i w: %i h: %i", p1.x, p1.y, p1.w, p1.h);

				direction = mc->direction;

				if (p1.y <= p2.y || p1.y >= p2.h) { // balle haut ou bas
					direction.x *= -1;
					SDL_Log("haut ou bas");
				}

				if (p1.x <= p2.x || p1.x >= p2.w) { // balle droite ou gauche
					direction.y *= -1;
					SDL_Log("droite ou gauche");
				}

				SDL_Log("%f %f\n", direction.x, direction.y);
				mc->direction = direction;
			}
		}

		tc = nullptr;
		mc = nullptr;
		cc1 = cc2 = nullptr;
		hc = nullptr;
	}
}
