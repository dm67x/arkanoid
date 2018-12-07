#include "scene_manager.h"
#include "System/system.h"

void SceneManager::add(Scene & s) {
	scenes.insert(std::make_pair(s.getName(), &s));
}

void SceneManager::remove(const std::string name) {
	scenes.erase(name);
}

void SceneManager::goTo(const std::string name) {
	// transition
	
	// charger la scene voulue
	current = scenes.at(name);
	// charger les entités dans la pool d'entité
	if (current) {
		System::setScene(*current);
		current->load();
	}
}

void SceneManager::clean() {
	for (auto s : scenes) {
		delete s.second;
	}

	scenes.clear();
}