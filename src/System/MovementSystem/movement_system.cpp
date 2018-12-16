#include "movement_system.h"
#include "Entity/entity.h"
#include "Component/transform.h"
#include "Component/motion.h"

using namespace Components;

void MovementSystem::update(double deltaTime) {
    System::update(deltaTime);

    for (auto entity : entity_manager->get()) {
        Transform * tc = entity->get<Transform>("transform");
        Motion * mc = entity->get<Motion>("motion");

        if (!tc || !mc) continue;

        tc->position.x += mc->velocity.x * deltaTime * 60.0f;
        tc->position.y += mc->velocity.y * deltaTime * 60.0f;

        if (tc->position.x > current->getWidth()) {
            tc->position.x = 0;
        } else if (tc->position.x < 0) {
            tc->position.x = current->getWidth();
        }

        if (tc->position.y < 0) {
            tc->position.y = 0;
            mc->velocity.y *= -1;
        }
        else if (tc->position.y > current->getHeight()) {
            event_manager->trigger("remove_ball_from_player", nullptr);
        }
    }
}