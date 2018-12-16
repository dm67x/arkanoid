#include "game.h"
#include "Scene/GameScene/game_scene.h"
#include "Scene/GameOverScene/game_over_scene.h"
#include "Scene/MenuScene/menu_scene.h"

#include <iostream>

Game::Game() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "Echec de l'initialisation de la SDL " <<
            SDL_GetError() << std::endl;
        exit(1);
    }

	window = Singleton<Window>::getInstance();
    quit = false;
	scene_manager = Singleton<SceneManager>::getInstance();
}

Game::~Game() {
	scene_manager->clean();

    SDL_Quit();
}

void Game::init() {
	Scene * gameScene = new Scenes::GameScene();
	gameScene->setSize(window->getSize().x, window->getSize().y);
	scene_manager->add(*gameScene);

	Scene * gameOverScene = new Scenes::GameOverScene();
	gameOverScene->setSize(window->getSize().x, window->getSize().y);
	scene_manager->add(*gameOverScene);

	Scene * menuScene = new Scenes::MenuScene();
	menuScene->setSize(window->getSize().x, window->getSize().y);
	scene_manager->add(*menuScene);

	scene_manager->load("menu");
}

void Game::run() {
    init();

	Uint64 now = SDL_GetPerformanceCounter();
	Uint64 prev;
	double deltaTime;

    while (!quit) {
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
				this->quit = true;
            else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
					this->quit = true;
            }

			scene_manager->getCurrent()->input(event);
        }

		prev = now;
		now = SDL_GetPerformanceCounter();
		deltaTime = (double)((now - prev)*1000 / (double)SDL_GetPerformanceFrequency() * 0.001);

		scene_manager->getCurrent()->update(deltaTime);

		if (deltaTime < 0.02) {
			SDL_Delay(0.02 - deltaTime);
			now = SDL_GetPerformanceCounter();
			deltaTime = (double)((now - prev)*1000 / (double)SDL_GetPerformanceFrequency() * 0.001);
		}

		scene_manager->getCurrent()->draw(*window->getSurface());

		window->update();
    }
}
