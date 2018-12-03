#include "game.h"
#include "Entity/entity_factory.h"
#include "Scene/GameScene/game_scene.h"

#include <iostream>

Game::Game() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "Echec de l'initialisation de la SDL " <<
            SDL_GetError() << std::endl;
        exit(1);
    }

    window = new Window();
    quit = false;
    event_manager = Singleton<EventManager>::getInstance();
	scene_manager = Singleton<SceneManager>::getInstance();
}

Game::~Game() {
    delete window;
	scene_manager->clean();

    SDL_Quit();
}

void Game::init() {
	Scene * gameScene = new Scenes::GameScene();
	gameScene->setSize(window->getSize().x, window->getSize().y);
	scene_manager->add(*gameScene);
	scene_manager->goTo("game");

    event_manager->attach("quit", [this](void *) {
        this->quit = true;
    });
}

void Game::run() {
    init();

	Uint64 time_now = SDL_GetPerformanceCounter();
	Uint64 time_last = 0;
	float deltaTime = 0;

    while (!quit) {
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                event_manager->trigger("quit", nullptr);
            else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
                    event_manager->trigger("quit", nullptr);
            }

			scene_manager->getScene()->input(event);
        }

		time_last = time_now;
		time_now = SDL_GetPerformanceCounter();
		deltaTime = static_cast<float>(((time_now - time_last) * 1000) / SDL_GetPerformanceFrequency()) * 0.001f;

		scene_manager->getScene()->update(deltaTime);
		scene_manager->getScene()->draw(*window->getSurface());

        window->update();
    }
}
