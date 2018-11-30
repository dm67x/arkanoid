#include "scene_manager.h"

void SceneManager::add(Scene & s) {
	scenes.insert(std::make_pair(s.getName(), &s));
}

void SceneManager::remove(const std::string name) {
	scenes.erase(name);
}

void SceneManager::goTo(const std::string name) {
	// charger la scene voulue
	current = scenes.at(name);
	// charger les entit�s dans la pool d'entit�
	if (current) current->reload();
}

void SceneManager::clean() {
	for (auto s : scenes) {
		delete s.second;
	}

	scenes.clear();
}