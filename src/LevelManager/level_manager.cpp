#include "level_manager.h"

int LevelManager::next_id = 0;

LevelManager::~LevelManager() {
	for (auto l : levels) delete l;
	levels.clear();
}

void LevelManager::add(Level * l) {
	levels.push_back(l);
	if (levels.size() == 1) 
		current = levels[0];
}

void LevelManager::remove(Level * l) {
	for (auto it = levels.begin(); it != levels.end(); it++) {
		if ((*it)->getID() == l->getID()) {
			delete *it;
			levels.erase(it);
		}
	}
}

bool LevelManager::next() {
	if (levels.size() > next_id) {
		if (current) current->unload();
		current = levels[next_id++];
		if (current) current->load();
		return true;
	}
	return false;
}
