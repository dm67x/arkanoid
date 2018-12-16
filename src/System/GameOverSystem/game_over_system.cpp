#include "game_over_system.h"
#include "Entity/entity.h"
#include "Component/ball_number.h"
#include "Scene/scene_manager.h"
#include <cstdlib>

using namespace Components;

void GameOverSystem::update(double deltaTime) {
    System::update(deltaTime);

    for (auto entity : entity_manager->get()) {
        BallNumber * ball_number = entity->get<BallNumber>("ball_number");
        if (!ball_number) continue;
        if (ball_number->number <= 0) {
            Singleton<SceneManager>::getInstance()->load("game_over");
            return;
        }
    }
}