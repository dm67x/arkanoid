#ifndef GAME_H
#define GAME_H

#include "Window/Window.h"
#include "InputManager/InputManager.h"

class Game
{

private:
    Window * _window;
    bool _quit;
    SDL_Event _event;
    InputManager * _keyManager, * _mouseManager;

protected:
    void init();

public:
    Game();
    ~Game();

    void run();

};

#endif // GAME_H
