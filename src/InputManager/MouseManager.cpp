#include "MouseManager.h"

MouseManager::MouseManager() : InputManager() {

}

MouseManager::~MouseManager() {

}

void MouseManager::update(SDL_Event e) {
    if (_locked) return;

    if (e.type == SDL_MOUSEBUTTONDOWN) {
        for (auto pair : _down) {
            if (e.button.button == pair.first)
                pair.second(e);
        }
    } else if (e.type == SDL_MOUSEBUTTONUP) {
        for (auto pair : _up) {
            if (e.button.button == pair.first)
                pair.second(e);
        }
    }
}
