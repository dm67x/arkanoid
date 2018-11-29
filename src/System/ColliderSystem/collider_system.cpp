#include "collider_system.h"
#include "Entity/Brick/Brick.h"
#include <iostream>
#include <algorithm>

void ColliderSystem::update(float deltaTime) {
    Vector2<int> p1, p2;
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

                if (dx < 0) { // gauche
                    direction.x = -0.196f;
                } else if (dx > 0) { // droite
                    direction.x = 0.196f;
                } else { // centre
                    direction.x = 0;
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
        }
    }
}