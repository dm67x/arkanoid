#ifndef GAME_H
#define GAME_H

#include "Window/window.h"
#include "InputManager/input_manager.h"
#include "Entity/entity_factory.h"
#include "Player/player.h"
#include "System/Render/render.h"
#include "System/Collision/collision.h"

class Game
{

private:
    Window * _window;
    bool _quit;
    SDL_Event _event;
    InputManager * _key_manager, * _mouse_manager;
    EntityFactory * _entity_factory;

    Entity * _ball;
    Player * _player;

	Systems::Render * _renderer;
	Systems::Collision * _collision;

protected:
    void init();
    void update(double dt);
    void draw();

public:
    Game();
    ~Game();

    void run();

};

#endif // GAME_H
