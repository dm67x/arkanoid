#include "key_manager.h"

KeyManager::KeyManager() : InputManager() {

}

KeyManager::~KeyManager() {

}

void KeyManager::update(SDL_Event e) {
    if (locked) return;

    if (e.type == SDL_KEYDOWN) {
        for (auto pair : down) {
            if (e.key.keysym.sym == pair.first)
                pair.second(e);
        }
    } else if (e.type == SDL_KEYUP) {
        for (auto pair : up) {
            if (e.key.keysym.sym == pair.first)
                pair.second(e);
        }
    }
}
