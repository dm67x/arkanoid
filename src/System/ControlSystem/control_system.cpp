#include "control_system.h"

void ControlSystem::input(SDL_Event e) {
    if (!current_scene) return;

    EntityManager * entity_manager = current_scene->getEntityManager();
    
    if (e.type == SDL_MOUSEMOTION) {
        for (auto entity : entity_manager->getEntities()) {
            try {
                component_manager->getControls().at(entity);
                Components::Transform * tc = component_manager->getTransforms().at(entity);

                tc->position.x = e.motion.x;
            } catch (std::out_of_range) {
                continue;
            }
        }
    } /*else if (e.type == SDL_KEYDOWN) {
        if (e.key.keysym.scancode == SDL_SCANCODE_LEFT) {
            for (auto entity : entity_manager->getEntities()) {
                try {
                    component_manager->getControls().at(entity);
                    Components::Transform * tc = component_manager->getTransforms().at(entity);

                    tc->position.x--;
                } catch (std::out_of_range) {
                    continue;
                }
            }
        } else if (e.key.keysym.scancode == SDL_SCANCODE_RIGHT) {
            for (auto entity : entity_manager->getEntities()) {
                try {
                    component_manager->getControls().at(entity);
                    Components::Transform * tc = component_manager->getTransforms().at(entity);

                    tc->position.x++;
                } catch (std::out_of_range) {
                    continue;
                }
            }
        }
    }*/
}