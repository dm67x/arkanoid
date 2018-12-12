#include "game.h"
#include "Scene/GameScene/game_scene.h"

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
	scene_manager->goTo("game");
}

void Game::run() {
    init();

	Uint64 time_now = SDL_GetPerformanceCounter();
	Uint64 time_last = 0;
	Uint64 passed_time = 0;
	float deltaTime = 0;
	const int FPS = 30;

    while (!quit) {
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
				this->quit = true;
            else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
					this->quit = true;
            }

			scene_manager->getScene()->input(event);
        }

		time_last = time_now;
		time_now = SDL_GetPerformanceCounter();
		passed_time = (time_now - time_last) * 1000 / SDL_GetPerformanceFrequency();
		deltaTime = static_cast<float>(passed_time * 0.001f);

		/*if (passed_time < (1000/FPS)) {
			SDL_Delay((1000/FPS) - passed_time);
		}*/

		scene_manager->getScene()->update(deltaTime);
		scene_manager->getScene()->draw(*window->getSurface());

        window->update();

		SDL_Delay(20);
    }
}
