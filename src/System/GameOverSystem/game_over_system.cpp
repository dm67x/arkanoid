#include "game_over_system.h"
#include "Entity/entity.h"
#include "Component/ball_number.h"
#include <cstdlib>

using namespace Components;

void GameOverSystem::update(double deltaTime) {
    System::update(deltaTime);

    EntityManager * manager = current->getManager();

    for (auto entity : manager->get()) {
        BallNumber * ball_number = entity->get<BallNumber>("ball_number");
        if (!ball_number) continue;
        if (ball_number->number <= 0) exit(0);
    }
}