#include "collider_system.h"
#include "Entity/Brick/Brick.h"

void ColliderSystem::update(float deltaTime) {
    Vector2<int> p1, p2, direction;
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
                    direction.x = -1;
                } else if (dx > 0) { // droite
                    direction.x = 1;
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

                entity->setDirection(direction);
            }
        }
    }
}