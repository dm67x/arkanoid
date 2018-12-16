#include "scene_manager.h"
#include "System/system.h"

void SceneManager::add(Scene & s) {
	scenes.insert(std::make_pair(s.getName(), &s));
}

void SceneManager::remove(const std::string name) {
	scenes.erase(name);
}

void SceneManager::load(const std::string name) {
	// transition
	
	// rendre inactif les entites actifs
	if (current) current->unload();
	// charger la scene voulue
	current = scenes.at(name);
	// charger la scene courante
	if (current) current->load();
}

void SceneManager::clean() {
	for (auto s : scenes) {
		delete s.second;
	}

	scenes.clear();
}