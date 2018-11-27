#include "collider_system.h"
#include "Entity/Brick/Brick.h"

void ColliderSystem::update(float deltaTime) {
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
                    
                entity->setDirection(entity->getDirection() * Vector2<int>(0, -1));
            }
        }
    }
}