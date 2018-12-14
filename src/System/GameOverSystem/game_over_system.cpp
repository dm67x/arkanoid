#include "game_over_system.h"
#include "Entity/entity.h"
#include "Component/ball_number.h"
#include <cstdlib>

void GameOverSystem::update(double deltaTime) {
    if (!current_scene) return;
    EntityManager * manager = current_scene->getEntityManager();

    for (auto entity : manager->get()) {
        Components::BallNumber * ball_number = static_cast<Components::BallNumber *>(entity->get("ball_number"));
        if (!ball_number) continue;
        if (ball_number <= 0) exit(0);
    }
}