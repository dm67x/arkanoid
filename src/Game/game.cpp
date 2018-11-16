#include "game.h"
#include "InputManager/key_manager.h"
#include "InputManager/mouse_manager.h"
#include "Entity/Ball/ball.h"

#include <iostream>

Game::Game() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "Echec de l'initialisation de la SDL " <<
            SDL_GetError() << std::endl;
        exit(1);
    }

    _window = new Window();
    _quit = false;
    _key_manager = new KeyManager();
    _mouse_manager = new MouseManager();
    _entity_factory = Singleton<EntityFactory>::getInstance();
    _player = new Player("player1");
    _ball = nullptr;
	_renderer = new Systems::Render();
	_collision = new Systems::Collision();
}

Game::~Game() {
    delete _window;
    delete _key_manager;
    delete _mouse_manager;

    delete _player;
    delete _ball;

	delete _renderer;
	delete _collision;

    SDL_Quit();
}

void Game::init() {
    _key_manager->addAction(SDLK_ESCAPE, [this](SDL_Event) {
        this->_quit = true;
    });

    _mouse_manager->addAction(SDL_BUTTON_LEFT, [](SDL_Event e) {
        std::cout << "mouse click, X: " << e.button.x << ", Y: " << e.button.y << std::endl;
    });

    _ball = _entity_factory->create("ball");

	Vector2<int> window_size = _window->getSize();
	_player->getShip()->setPosition(Vector2<int>(window_size._x / 2, window_size._y - 20));
	_ball->setPosition(Vector2<int>(window_size._x / 2, window_size._y / 2));
}

void Game::update(double dt) {
	_collision->update(dt);
}

void Game::draw() {
	_renderer->draw(*_window->getSurface());
}

void Game::run() {
    init();

    Uint64 old_time = 0;
    Uint64 new_time = SDL_GetPerformanceCounter();
    double delta = 0;

    while (!_quit) {
        if (SDL_PollEvent(&_event)) {
            _key_manager->update(_event);
            _mouse_manager->update(_event);

            if (_event.type == SDL_QUIT)
                _quit = true;
            else if (_event.type == SDL_MOUSEMOTION) {
                int x = _event.motion.x;
                _player->getShip()->setPosition(
                    Vector2<int>(x, _player->getShip()->getPosition()._y)
                );
            }
        }

        old_time = new_time;
        new_time = SDL_GetPerformanceCounter();
        delta = ((new_time - old_time)*1000.0) / static_cast<double>(SDL_GetPerformanceFrequency());
        update(delta);

        SDL_FillRect(_window->getSurface(), nullptr, 0x000000);
        draw();

        _window->update();
        SDL_Delay(20);
    }
}
