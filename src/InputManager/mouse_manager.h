#ifndef MOUSEMANAGER_H
#define MOUSEMANAGER_H

#include "input_manager.h"

class MouseManager : public InputManager
{

public:
    MouseManager();
    ~MouseManager();

    void update(SDL_Event e);

};

#endif // MOUSEMANAGER_H
