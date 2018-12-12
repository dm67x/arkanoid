#include <iostream>
#include <cassert>

#include "game_scene.h"
#include "System/RenderSystem/render_system.h"
#include "System/ControlSystem/control_system.h"
#include "Entity/Ship/ship.h"
#include "Entity/Ball/ball.h"

using namespace Scenes;

GameScene::GameScene() : Scene("game") {
	// Attacher l'evenement permettant de detruire une entite
}

GameScene::~GameScene() {
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

	// Creation de l'entite "ship"
	Entities::Ship * ship = new Entities::Ship(entity_manager);
	ship->transform->position = Vector2<float>(getWidth() / 2, getHeight() - 20.0f);

	// Creation de l'entité balle
	Entities::Ball * ball = new Entities::Ball(entity_manager);
	ball->transform->position = Vector2<float>(getWidth() / 2, ship->transform->position.y - 25.0f);

	/*Ship * ship = new Ship(pool);
	ship->transform->position.y = getHeight() - 20.0f;

	/*Ship * ship2 = new Ship(pool);
	ship2->transform->position.y = 20.0f;*/

	// Creation de l'entite "ball"
	/*Ball * ball = new Ball(pool);
	ball->transform->position.y = 
		ship->collision->getBoundingBox().y - ball->render->src.h / 2.0f;

	// Creation du texte pour le score
	/*Text * score = new Text(pool, "Score: 0");
	score->transform->position = Vector2<float>(10, 10);
	score->transform->scale = Vector2<float>(0.6f, 0.6f);*/
}