#include <iostream>
#include <cassert>

#include "game_scene.h"
#include "System/RenderSystem/render_system.h"
#include "System/ControlSystem/control_system.h"
#include "System/CollisionSystem/collision_system.h"
#include "System/MovementSystem/movement_system.h"
#include "Entity/Ship/ship.h"
#include "Entity/Ball/ball.h"
#include "Entity/Brick/brick.h"

#include "Level/level.h"

using namespace Scenes;

GameScene::GameScene() : Scene("game") {
	event_manager->attach("destroy_entity", [this](void * param) {
		Entity id = *(static_cast<Entity *>(param));
		entity_manager->removeEntity(id);
	});
	
	Level * niveau1 = new Level("level1.txt");
	entity_manager = niveau1->getManager();
}

GameScene::~GameScene() {
	event_manager->detach("destroy_entity");
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

	// Creation de l'entite "ship"
	Entities::Ship * ship = new Entities::Ship(entity_manager);
	ship->transform->position = Vector2<float>(getWidth() / 2, getHeight() - 20.0f);

	// Creation de l'entité balle
	Entities::Ball * ball = new Entities::Ball(entity_manager);
	ball->transform->position = Vector2<float>(getWidth() / 2, ship->transform->position.y - 40.0f);
}
