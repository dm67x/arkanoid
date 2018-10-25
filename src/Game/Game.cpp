#include "Game.h"
#include "InputManager/KeyManager.h"
#include "InputManager/MouseManager.h"
#include "Entity/Ball/Ball.h"
#include "Entity/Ship/Ship.h"

#include <iostream>

Game::Game() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cerr << "Echec de l'initialisation de la SDL " << 
			SDL_GetError() << std::endl;
		exit(1);
    }

    _window = new Window();
    _quit = false;
    _keyManager = new KeyManager();
    _mouseManager = new MouseManager();
}

Game::~Game() {
    delete _window;
    delete _keyManager;
    delete _mouseManager;
    delete _ship;
    delete _ball;
    SDL_Quit();
}

void Game::init() {
    _keyManager->addAction(SDLK_ESCAPE, [this](SDL_Event) {
        this->_quit = true;
    });

    _mouseManager->addAction(SDL_BUTTON_LEFT, [](SDL_Event e) {
        std::cout << "mouse click, X: " << e.button.x << ", Y: " << e.button.y << std::endl;
    });

    _ball = new Ball();
    _ball->add(_window);
    _ball->init();

    _ship = new Ship();
    _ship->add(_window);
    _ship->init();
}

void Game::update() {
    _ball->update();
    _ship->update();
}

void Game::draw() {
    _ball->draw();
    _ship->draw();
}

void Game::run() {
    init();

    while (!_quit) {
        if (SDL_PollEvent(&_event)) {
            _keyManager->update(_event);
            _mouseManager->update(_event);

            if (_event.type == SDL_QUIT)
                _quit = true;
        }

        update();
        draw();

        _window->update();
        SDL_Delay(20);
    }
}
