#include "collider_system.h"
#include "Entity/Brick/brick.h"
#include "Window/window.h"
#include <iostream>
#include <algorithm>
#include <cmath>

void ColliderSystem::update(float deltaTime) {
	if (!pool) return;

    Vector2<float> p1, p2;
    Vector2<float> direction, reflection, d;
    int dx = 0, dy = 0;

    for (auto entity : pool->all("ball")) {
        for (auto entity2 : pool->all()) {
            if (entity == entity2) continue;

            if (entity->collideWith(*entity2)) {
                if (entity2->getType() == "brick") {
                    Entities::Brick * brick = dynamic_cast<Entities::Brick*>(entity2);
                    if (brick) {
                        brick->damage();
                    }
                }

                p1 = entity->getPosition();
                p2 = entity2->getPosition();
                dx = p1.x - p2.x;
                dy = p1.y - p2.y;

				if (dx == 0) { // centre
					direction.x = 0;
				} else { // droite ou gauche
                    direction.x = dx < 0 ? -0.2f : 0.2f;
                }

                if (dy < 0) { // haut
                    direction.y = -1;
                } else if (dy > 0) { // bas
                    direction.y = 1;
                } else {
                    direction.y = 0;
                }
                

                d = entity->getDirection();
                reflection.x = d.x - 2.0 * (d.x * direction.x + d.y * direction.y) * direction.x;
                reflection.y = d.y - 2.0 * (d.x * direction.x + d.y * direction.y) * direction.y;

                float norm = sqrt(reflection.x * reflection.x + reflection.y * reflection.y);
                reflection.x /= norm;
                reflection.y /= norm;

                std::cout << reflection.x << " " << reflection.y << std::endl;
                entity->setDirection(reflection);
            }

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
    }
}
