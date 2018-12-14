#include <iostream>
#include <cassert>

#include "game_scene.h"
#include "System/RenderSystem/render_system.h"
#include "System/ControlSystem/control_system.h"
#include "System/CollisionSystem/collision_system.h"
#include "System/MovementSystem/movement_system.h"
#include "Entity/Player/player.h"
#include "Entity/Brick/brick.h"
#include "Level/level.h"

using namespace Scenes;

GameScene::GameScene() : Scene("game") {
	event_manager->attach("destroy_entity", [this](void * param) {
		unsigned int id = *(static_cast<unsigned int *>(param));
		entity_manager->remove(id);
	});
	
	/*Level * niveau1 = new Level("level1.txt");
	entity_manager = niveau1->getManager();*/

	entity_manager = new EntityManager();
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

	new Entities::Player("Joueur 1", Vector2<float>(getWidth() / 2, getHeight() - 20.0f), entity_manager);
}
