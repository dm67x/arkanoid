#include "control_system.h"
#include "Entity/entity.h"
#include "Component/control.h"
#include "Component/transform.h"
#include "Component/motion.h"

using namespace Components;

void ControlSystem::input(SDL_Event e) {
    if (!current_scene) return;

    EntityManager * entity_manager = current_scene->getEntityManager();
    
    if (e.type == SDL_MOUSEMOTION) {
        for (auto entity : entity_manager->get()) {
            Transform * tc = entity->get<Transform>("transform");
            if (!tc || !entity->get<Component>("control")) continue;
            tc->position.x = e.motion.x;
        }
    } else if (e.type == SDL_MOUSEBUTTONDOWN) {
        for (auto entity : entity_manager->get()) {
            Motion * mc = entity->get<Motion>("motion");
            if (!mc || !entity->get<Component>("control")) continue;
            mc->velocity.y = 7;
            mc->velocity.x = 5;
            entity->remove("control");
        }
    } 
    
    /*else if (e.type == SDL_KEYDOWN) {
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