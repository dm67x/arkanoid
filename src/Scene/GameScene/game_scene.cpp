#include "game_scene.h"
#include "System/RenderSystem/render_system.h"
#include "System/ColliderSystem/collider_system.h"
#include "System/MovementSystem/movement_system.h"
#include "System/FontSystem/font_system.h"
#include "Entity/Text/text.h"
#include <iostream>

using namespace Scenes;

GameScene::GameScene() : Scene("game") {
	pool = new EntityPool();
	reload();
}

GameScene::~GameScene() {
	delete pool;
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

	Entity * ship = entity_factory->build("ship");
	ship->setPosition(Vector2<float>(getWidth() / 2.0f, getHeight() - 20));

	Entity * ball = entity_factory->build("ball");
	ball->setPosition(Vector2<float>(getWidth() / 2.0f, getHeight() - 40));

	Entity * brick = nullptr;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			brick = entity_factory->build("brick");
			brick->setPosition(Vector2<float>(100 + i * 40, 100 + j * 50));
		}
	}

	Entity * text = entity_factory->build("text");
	text->setPosition(Vector2<float>(10, 10));
	Entities::Text * dtext = dynamic_cast<Entities::Text *>(text);
	if (dtext) {
		dtext->setText("Player 1");
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
	if (e.type == SDL_MOUSEBUTTONDOWN)
		event_manager->trigger("launch_ball", nullptr);

	for (auto s : systems) s->input(e);
}