#ifndef GAME_H
#define GAME_H

#include "Window/Window.h"
#include "InputManager/InputManager.h"
#include "Entity/Entity.h"

class Game
{

private:
    Window * _window;
    bool _quit;
    SDL_Event _event;
    InputManager * _keyManager, * _mouseManager;

    // Entities
    Entity * _ball;
    Entity * _ship;

protected:
    void init();
    void update();
    void draw();

public:
    Game();
    ~Game();

    void run();

};

#endif // GAME_H
