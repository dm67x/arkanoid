#include "KeyManager.h"

KeyManager::KeyManager() : InputManager() {

}

KeyManager::~KeyManager() {

}

void KeyManager::update(SDL_Event e) {
    if (_locked) return;

    if (e.type == SDL_KEYDOWN) {
        for (auto pair : _down) {
            if (e.key.keysym.sym == pair.first)
                pair.second(e);
        }
    } else if (e.type == SDL_KEYUP) {
        for (auto pair : _up) {
            if (e.key.keysym.sym == pair.first)
                pair.second(e);
        }
    }
}
