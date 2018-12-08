#include "game_scene.h"
#include "System/RenderSystem/render_system.h"
#include "System/ColliderSystem/collider_system.h"
#include "System/MovementSystem/movement_system.h"
#include "System/FontSystem/font_system.h"
#include "Entity/Text/text.h"
#include "Entity/Brick/brick.h"
#include <iostream>
#include <cassert>

using namespace Scenes;

GameScene::GameScene() : Scene("game") {
	// Attacher l'evenement permettant de détruire une entité
	event_manager->attach("destroy_entity", [this](void * brick) {
		Entity * b = static_cast<Entity *>(brick);
		if (b) {
			this->destroyEntity(*b);
		}
	});
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
	systems.push_back(new FontSystem(*font));
	systems.push_back(new ColliderSystem());
	systems.push_back(new MovementSystem());

	try {
		Entity * ship = entity_factory->build("ship");
		ship->setPosition(Vector2<float>(0, getHeight() - 20.0f));
		addEntity(*ship);

		Entity * ball = entity_factory->build("ball");
		ball->setPosition(Vector2<float>(0, ship->getBoundingBox().y - ball->getGraphic().h / 2.0f));
		addEntity(*ball);

		Entities::Brick * brick = nullptr;
		int pts = 0;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				brick = dynamic_cast<Entities::Brick *>(entity_factory->build("brick"));
				brick->setPosition(Vector2<float>(100.0f + i * 40.0f, 100.0f + j * 50.0f));
				pts = (pts + 50) % 130;
				brick->setPoints(pts);
				addEntity(*brick);
			}
		}

		Entities::Text * text = dynamic_cast<Entities::Text *>(entity_factory->build("text"));
		text->setPosition(Vector2<float>(10, 10));
		text->setText("0");
		addEntity(*text);
	}
	catch (std::string err) {
		std::cerr << err << std::endl;
		exit(1);
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