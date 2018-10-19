#include "Game.h"
#include "InputManager/KeyManager.h"
#include "InputManager/MouseManager.h"

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
    SDL_Quit();
}

void Game::init() {
    _keyManager->addAction(SDLK_ESCAPE, [this](SDL_Event) {
        this->_quit = true;
    });

    _mouseManager->addAction(SDL_BUTTON_LEFT, [this](SDL_Event e) {
        std::cout << "mouse click, X: " << e.button.x << ", Y: " << e.button.y << std::endl;
    });
}

void Game::run() {
    init();

    while (!_quit) {
        if (SDL_PollEvent(&_event)) {
            _keyManager->update(_event);
            _mouseManager->update(_event);

            switch (_event.type)
			{
                case SDL_QUIT:
                    _quit = true;
                    break;
                /*case SDL_KEYDOWN:
                    switch (_event.key.keysym.sym)
                    {
                        // touche clavier
                        //case SDLK_LEFT:  x_vault -= 10; break;
                        //case SDLK_RIGHT: x_vault +=10; break;
                        case SDLK_ESCAPE: _quit = true; break;
                        default: break;
                    }
                    break;*/
                //case SDL_MOUSEMOTION:	x_vault += event.motion.xrel;	break;
                default: break;
			}
        }

        _window->update();
        SDL_Delay(20);
    }
}
