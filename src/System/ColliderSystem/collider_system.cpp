#include <iostream>
#include <algorithm>
#include <cmath>

#include "collider_system.h"
#include "Window/window.h"
#include "Component/collision_component.h"
#include "Component/movement_component.h"

void ColliderSystem::update(float deltaTime) {
	if (!current_scene) return;

	Vector2<float> p1, p2;
	Vector2<float> direction, reflection, d;
	int dx = 0, dy = 0;

	EntityPool * pool = current_scene->getPool();
	CollisionComponent * cc1 = nullptr, *cc2 = nullptr;
	MovementComponent * mc = nullptr;

	for (auto entity : pool->getEntities()) {
		if (entity.first != 0x02) continue; // continuer si pas balle
		for (auto comp : entity.second) {
			if (comp->getName() == "collision") {
				cc1 = static_cast<CollisionComponent *>(comp);
			}
			else if (comp->getName() == "movement") {
				mc = static_cast<MovementComponent *>(comp);
			}
		}

		if (!cc1 || !mc) continue; // si pas de composant de collision ou movement continuer

		for (auto entity2 : pool->getEntities()) {
			if (entity.first == entity2.first || entity2.first == 0x02)
				continue; // continuer si la meme entité ou une balle

			for (auto comp : entity2.second) {
				if (comp->getName() == "collision") {
					cc2 = static_cast<CollisionComponent *>(comp);
				}
			}

			if (!cc2) continue; // si pas de composant de collision continuer

			if (cc1->collide(cc2->getBoundingBox())) { // si collision
				p1 = cc1->transform->position;
				p2 = cc2->transform->position;
				dx = static_cast<int>(p1.x - p2.x);
				dy = static_cast<int>(p1.y - p2.y);

				if (dx == 0) { // centre
					direction.x = 0;
				}
				else { // droite ou gauche
					direction.x = dx < 0 ? -0.2f : 0.2f;
				}

				if (dy < 0) { // haut
					direction.y = -1;
				}
				else if (dy > 0) { // bas
					direction.y = 1;
				}
				else {
					direction.y = 0;
				}


				d = mc->direction;
				reflection.x = d.x - 2.0f * (d.x * direction.x + d.y * direction.y) * direction.x;
				reflection.y = d.y - 2.0f * (d.x * direction.x + d.y * direction.y) * direction.y;
				reflection.normalize();

				SDL_Log("%d %d\n", reflection.x, reflection.y);
				mc->direction = reflection;
			}
		}

		mc = nullptr;
		cc1 = cc2 = nullptr;
	}

	/*for (auto entity : entities) {
		if (entity->getType() != "ball") continue;

		for (auto entity2 : entities) {
			if (entity == entity2) continue;

			if (entity->collideWith(*entity2)) {
				if (entity2->getType() == "brick") {
					Entities::Brick * brick = dynamic_cast<Entities::Brick*>(entity2);
					if (brick) {
						brick->damage();
					}
				}


			}*/

			// Pour la scene circulaire
			/*SDL_Rect bounding = entity->getBoundingBox();
			Vector2<int> window_size = Singleton<Window>::getInstance()->getSize();
			direction = entity->getDirection();

			if (bounding.x + bounding.w < 0) {
				entity->setPosition(Vector2<float>(window_size.x, bounding.y));
			}
			else if (bounding.x - bounding.w > window_size.x) {
				entity->setPosition(Vector2<float>(0, bounding.y));
			}
			else if (bounding.y + bounding.h < 0) {
				entity->setDirection(Vector2<float>(direction.x, 1));
			}*/
}
