#ifndef GAME_H
#define GAME_H

#include "Window/window.h"
#include "InputManager/input_manager.h"
#include "System/render_system.h"

class Game
{

private:
    Window * window;
    bool quit;
    SDL_Event event;
    InputManager * key_manager, * mouse_manager;
    
    RenderSystem * render_system;

protected:
    void init();

public:
    Game();
    ~Game();

    void run();

};

#endif // GAME_H
