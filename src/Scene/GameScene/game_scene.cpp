#include <iostream>
#include <cassert>

#include "game_scene.h"
#include "System/RenderSystem/render_system.h"
#include "System/ControlSystem/control_system.h"
#include "System/CollisionSystem/collision_system.h"
#include "System/MovementSystem/movement_system.h"
#include "System/GameOverSystem/game_over_system.h"
#include "Entity/Brick/brick.h"
#include "Component/transform.h"
#include "Component/motion.h"
#include "Component/bonus.h"
#include "Entity/Bonus/bonus.h"
#include "Component/ball_number.h"
#include "Level/level.h"

using namespace Scenes;

GameScene::GameScene() : Scene("game") {
	entity_manager = new EntityManager();

	event_manager->attach("destroy_entity", [this](void * param) {
		Entity * entity = static_cast<Entity *>(param);
		if (!entity) return;
		Components::Bonus * bonus = entity->get<Components::Bonus>("bonus");
		if (bonus->bonus != 0) {
			Entities::Bonus * b = new Entities::Bonus(entity_manager);
			b->get<Components::Transform>("transform")->position = entity->get<Components::Transform>("transform")->position;
			b->get<Components::Motion>("motion")->velocity = Vector2<float>(0, 1);
		}
		std::cout << entity->getID() << std::endl;
		entity_manager->remove(entity->getID());
	});

	event_manager->attach("remove_ball_from_player", [this](void * param) {
		if (!player) return;
		Components::BallNumber * number = player->get<Components::BallNumber>("ball_number");
		if (number) {
			number->number -= 1;
		}
	});
	
	Level * niveau1 = new Level("level1.txt");
	entity_manager = niveau1->getManager();
}

GameScene::~GameScene() {
	event_manager->detach("destroy_entity");
	event_manager->detach("remove_ball_from_player");
}

void GameScene::load() {
	SDL_Surface * sprite = SDL_LoadBMP("./Arkanoid_sprites.bmp");
	SDL_Surface * font = SDL_LoadBMP("./Arkanoid_ascii.bmp");

	if (!sprite || !font) {
		std::cerr << "error on reading assets files" << std::endl;
		exit(1);
	}

	systems.push_back(new RenderSystem(*sprite));
	systems.push_back(new ControlSystem());
	systems.push_back(new CollisionSystem());
	systems.push_back(new MovementSystem());
	systems.push_back(new GameOverSystem());

	player = new Entities::Player("Joueur 1", Vector2<float>(getWidth() / 2, getHeight() - 20.0f), entity_manager);

	Entities::Brick * brick = new Entities::Brick(entity_manager);
	brick->get<Components::Transform>("transform")->position = Vector2<float>(150, 150);
}
