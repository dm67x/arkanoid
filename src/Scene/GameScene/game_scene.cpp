#include "game_scene.h"
#include "System/RenderSystem/render_system.h"
#include "System/ColliderSystem/collider_system.h"
#include "System/MovementSystem/movement_system.h"
#include "Entity/Ball/ball.h"
#include "Entity/Ship/ship.h"
#include "Entity/Brick/brick.h"

using namespace Scenes;

GameScene::GameScene() : Scene("game") {
	pool = new EntityPool();
	reload();
}

GameScene::~GameScene() {
	delete pool;
}

void GameScene::load() {
	systems.push_back(new RenderSystem(SDL_LoadBMP("./Arkanoid_sprites.bmp")));
	systems.push_back(new ColliderSystem());
	systems.push_back(new MovementSystem());

	Entity * ship = entity_factory->build("ship");
	ship->setPosition(Vector2<float>(400, 500));

	Entity * ball = entity_factory->build("ball");
	ball->setPosition(Vector2<float>(400, 480));

	Entity * brick = nullptr;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			brick = entity_factory->build("brick");
			brick->setPosition(Vector2<float>(100 + i * 40, 100 + j * 50));
		}
	}
}

void GameScene::update(float deltaTime) {
	for (auto s : systems) s->update(deltaTime);
}

void GameScene::draw(SDL_Surface & surface) {
	for (auto s : systems) s->draw(surface);
}

void GameScene::input(SDL_Event e) {
	for (auto s : systems) s->input(e);
}