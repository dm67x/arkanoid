#include "collision_system.h"

void CollisionSystem::update(double deltaTime) {
    if (!current_scene) return;
    EntityManager * entity_manager = current_scene->getEntityManager();

    for (auto entity : entity_manager->getEntities()) {
        try {
            component_manager->getCollisions().at(entity);
            Components::Transform * tc = component_manager->getTransforms().at(entity);
            Components::Sprite * sc = component_manager->getSprites().at(entity);
            Components::Motion * mc = component_manager->getMotions().at(entity);

            for (auto entity2 : entity_manager->getEntities()) {
                if (entity == entity2) continue;

                try {
                    component_manager->getCollisions().at(entity2);
                    Components::Transform * tc2 = component_manager->getTransforms().at(entity2);
                    Components::Sprite * sc2 = component_manager->getSprites().at(entity2);
                
                    SDL_Rect box1, box2;
                    box1.x = static_cast<int>(tc->position.x - (sc->src.w / 2) * tc->scale.x);
                    box1.y = static_cast<int>(tc->position.y - (sc->src.h / 2) * tc->scale.y);
                    box1.w = static_cast<int>(tc->position.x + (sc->src.w / 2) * tc->scale.x);
                    box1.h = static_cast<int>(tc->position.y + (sc->src.h / 2) * tc->scale.y);

                    box2.x = static_cast<int>(tc2->position.x - (sc2->src.w / 2) * tc2->scale.x);
                    box2.y = static_cast<int>(tc2->position.y - (sc2->src.h / 2) * tc2->scale.y);
                    box2.w = static_cast<int>(tc2->position.x + (sc2->src.w / 2) * tc2->scale.x);
                    box2.h = static_cast<int>(tc2->position.y + (sc2->src.h / 2) * tc2->scale.y);
                
                    if (box1.x <= box2.w && box1.w >= box2.x 
                        && box1.y <= box2.h && box1.h >= box2.y) 
                    {
                        // Collision
                        if (box1.y <= box2.y || box1.y >= box2.h) { // balle haut ou bas
                            mc->velocity.y *= -1;
                        }
                    }
                }
                catch (std::out_of_range) {
                    continue;
                }
            }

        } catch (std::out_of_range) {
            continue;
        }
    }
}