#include "movement_system.h"

void MovementSystem::update(float deltaTime) {
    if (!current_scene) return;
    EntityManager * entity_manager = current_scene->getEntityManager();

    for (auto entity : entity_manager->getEntities()) {
        try {
            Components::Transform * tc = component_manager->getTransforms().at(entity);
            Components::Motion * mc = component_manager->getMotions().at(entity);
        
            tc->position.x += mc->velocity.x;
            tc->position.y += mc->velocity.y;
        } catch (std::out_of_range) {
            continue;
        }
    }
}