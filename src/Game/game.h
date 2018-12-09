#ifndef GAME_H
#define GAME_H

#include "Window/window.h"
#include "EventManager/event_manager.h"
#include "Scene/scene_manager.h"

class Game
{

private:
    Window * window;
    bool quit;
    SDL_Event event;
	SceneManager * scene_manager;
    
protected:
    void init();

public:
    Game();
    ~Game();

    void run();

};

#endif // GAME_H
