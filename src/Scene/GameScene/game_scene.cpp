#include <iostream>
#include <cassert>

#include "game_scene.h"
#include "System/RenderSystem/render_system.h"
#include "System/ControlSystem/control_system.h"
#include "System/CollisionSystem/collision_system.h"
#include "System/MovementSystem/movement_system.h"
#include "System/GameOverSystem/game_over_system.h"
#include "System/PointsBlockSystem/points_block_system.h"
#include "Entity/Brick/brick.h"
#include "Component/transform.h"
#include "Component/motion.h"
#include "Component/ball_number.h"
#include "Level/level.h"

using namespace Scenes;

GameScene::GameScene() : Scene("game") {
	event_manager->attach("remove_ball_from_player", [this](void * param) {
		if (!player) return;
		Components::BallNumber * number = player->get<Components::BallNumber>("ball_number");
		if (number) {
			number->number -= 1;
		}
	});
}

GameScene::~GameScene() {
	event_manager->detach("remove_ball_from_player");
}

void GameScene::load() {
	SDL_Surface * sprite = SDL_LoadBMP("./assets/Arkanoid_sprites.bmp");
	SDL_Surface * font = SDL_LoadBMP("./assets/Arkanoid_ascii.bmp");

	if (!sprite || !font) {
		std::cerr << "error on reading assets files" << std::endl;
		exit(1);
	}

	systems.push_back(new RenderSystem(*sprite));
	systems.push_back(new ControlSystem());
	systems.push_back(new CollisionSystem());
	systems.push_back(new MovementSystem());
	systems.push_back(new GameOverSystem());
	systems.push_back(new PointsBlockSystem());
	
	Level * niveau1 = new Level("./assets/levels/level4.txt");
	entity_manager = niveau1->getManager();
	
	player = new Entities::Player("Joueur 1", Vector2<float>(getWidth() / 2, getHeight() - 20.0f), entity_manager);
	
	
	
}
