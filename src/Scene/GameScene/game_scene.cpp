#include <iostream>
#include <cassert>

#include "game_scene.h"
#include "System/RenderSystem/render_system.h"
#include "System/ColliderSystem/collider_system.h"
#include "System/MovementSystem/movement_system.h"
#include "System/FontSystem/font_system.h"

#include "Entity/Ship/ship.h"
#include "Entity/Ball/ball.h"
#include "Entity/Brick/brick.h"
#include "Entity/Text/text.h"

using namespace Scenes;

GameScene::GameScene() : Scene("game") {
	// Attacher l'evenement permettant de d�truire une entit�
	event_manager->attach("destroy_entity", [this](void * ent) {
		Entity to_destroy = *(static_cast<Entity *>(ent));
		this->pool->remove(to_destroy);
	});
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
	systems.push_back(new FontSystem(*font));
	systems.push_back(new ColliderSystem());
	systems.push_back(new MovementSystem());

	// Creation de l'entit� "ship"
	Ship * ship = new Ship(0x01, pool);
	ship->transform->position.y = getHeight() - 20.0f;

	// Creation de l'entit� "ball"
	Ball * ball = new Ball(0x02, pool);
	ball->transform->position.y = ship->collision->getBoundingBox().y - ball->render->src.h / 2.0f;

	// Creation du texte pour le score
	Text * score = new Text(0x03, pool, "Score: 0");
	score->transform->position = Vector2<float>(10, 10);
	score->transform->scale = Vector2<float>(0.6f, 0.6f);

	// Creation des bricks de test
	int pts = 0;
	Brick * brick;
	Entity id = 0x04;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			pts = (pts + 50) % 130;
			brick = new Brick(id++, pool, pts);
			brick->transform->position = Vector2<float>(100.0f + i * 40.0f, 100.0f + j * 50.0f);
		}
	}
}

void GameScene::update(float deltaTime) {
	for (auto s : systems) s->update(deltaTime);
}

void GameScene::draw(SDL_Surface & surface) {
	SDL_FillRect(&surface, nullptr, 0x000000);
	for (auto s : systems) s->draw(surface);
}

void GameScene::input(SDL_Event e) {
	for (auto s : systems) s->input(e);
}