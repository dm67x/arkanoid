#include <iostream>
#include <cassert>

#include "game_scene.h"
#include "System/RenderSystem/render_system.h"
#include "System/ColliderSystem/collider_system.h"
#include "System/MovementSystem/movement_system.h"
#include "System/FontSystem/font_system.h"

#include "Component/transform_component.h"
#include "Component/render_component.h"
#include "Component/collision_component.h"
#include "Component/movement_component.h"

using namespace Scenes;

GameScene::GameScene() : Scene("game") {
	// Attacher l'evenement permettant de détruire une entité
	event_manager->attach("destroy_entity", [this](void * brick) {
		Entity to_destroy = *(static_cast<Entity *>(brick));
		this->pool->remove(to_destroy);
	});

	// Evenement permettant de bouger le navire avec la souris
	event_manager->attach("move_ship", [this](void * p) {
		SDL_Event * e = (SDL_Event *)p;
		for (auto comp : this->pool->getComponents(ship)) {
			if (comp->getName() == "transform") {
				TransformComponent * tc = static_cast<TransformComponent *>(comp);
				tc->position.x = e->motion.x;
			}
		}
	});

	// Evenement permettant de bouger la balle en fonction du navire (avant le commencement)
	event_manager->attach("move_ball_with_ship", [this](void * p) {
		SDL_Event * e = (SDL_Event *)p;
		TransformComponent * tc = nullptr;
		MovementComponent * mc = nullptr;

		for (auto comp : this->pool->getComponents(ball)) {
			if (comp->getName() == "transform") {
				tc = static_cast<TransformComponent *>(comp);
			}
			else if (comp->getName() == "movement") {
				mc = static_cast<MovementComponent *>(comp);
			}
		}

		if (tc && mc) {
			if (mc->is_static)
				tc->position.x = e->motion.x;
		}
	});

	// Evenement permettant de lancer une balle
	event_manager->attach("launch_ball", [this](void *) {
		MovementComponent * mc = nullptr;

		for (auto comp : this->pool->getComponents(ball)) {
			if (comp->getName() == "movement") {
				mc = static_cast<MovementComponent *>(comp);
			}
		}

		if (mc) {
			if (mc->is_static) {
				mc->is_static = false;
				mc->direction = Vector2<float>(0, -1);
			}
		}
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
	//systems.push_back(new FontSystem(*font));
	systems.push_back(new ColliderSystem());
	systems.push_back(new MovementSystem());

	// Creation de l'entité "ship"
	ship = 0x01;
	TransformComponent * ship_transform = new TransformComponent(ship);
	RenderComponent * ship_render = new RenderComponent(ship, { 385, 192, 98, 16 });
	MovementComponent * ship_movement = new MovementComponent(ship);
	CollisionComponent * ship_collision = new CollisionComponent(ship, ship_transform, ship_render);

	ship_transform->position.y = getHeight() - 20.0f;

	pool->add(ship, *ship_transform);
	pool->add(ship, *ship_render);
	pool->add(ship, *ship_movement);
	pool->add(ship, *ship_collision);

	// Creation de l'entité "ball"
	ball = 0x02;
	TransformComponent * ball_transform = new TransformComponent(ball);
	RenderComponent * ball_render = new RenderComponent(ball, { 80, 64, 16, 16 });
	MovementComponent * ball_movement = new MovementComponent(ball, 5.0f, Vector2<float>(0, -1), true);
	CollisionComponent * ball_collision = new CollisionComponent(ball, ball_transform, ball_render);

	ball_transform->position.y = ship_collision->getBoundingBox().y - ball_render->src.h / 2.0f;

	pool->add(ball, *ball_transform);
	pool->add(ball, *ball_render);
	pool->add(ball, *ball_movement);
	pool->add(ball, *ball_collision);

	/*try {
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
	}*/
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