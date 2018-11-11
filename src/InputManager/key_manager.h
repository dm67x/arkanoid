#ifndef KEYMANAGER_H
#define KEYMANAGER_H

#include "input_manager.h"

class KeyManager : public InputManager
{

public:
    KeyManager();
    ~KeyManager();

    void update(SDL_Event e);

};

#endif // KEYMANAGER_H
