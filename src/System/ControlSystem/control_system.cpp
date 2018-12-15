#include "control_system.h"
#include "Entity/entity.h"
#include "Component/control.h"
#include "Component/transform.h"
#include "Component/motion.h"

using namespace Components;

void ControlSystem::input(SDL_Event e) {
    System::input(e);

    EntityManager * entity_manager = current->getManager();
    
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
}