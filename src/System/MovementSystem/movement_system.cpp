#include "movement_system.h"

void MovementSystem::update(double deltaTime) {
    if (!current_scene) return;
    EntityManager * entity_manager = current_scene->getEntityManager();

    for (auto entity : entity_manager->getEntities()) {
        try {
            Components::Transform * tc = component_manager->getTransforms().at(entity);
            Components::Motion * mc = component_manager->getMotions().at(entity);
        
            tc->position.x += mc->velocity.x * deltaTime * 60.0f;
            tc->position.y += mc->velocity.y * deltaTime * 60.0f;

            if (tc->position.x > current_scene->getWidth()) {
                tc->position.x = 0;
            } else if (tc->position.x < 0) {
                tc->position.x = current_scene->getWidth();
            }

            if (tc->position.y < 0) {
                tc->position.y = 0;
                mc->velocity.y *= -1;
            }

        } catch (std::out_of_range) {
            continue;
        }
    }
}