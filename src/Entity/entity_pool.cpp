#include "entity_pool.h"

EntityPool::EntityPool() {
}

EntityPool::~EntityPool() {
}

void EntityPool::add(uint32_t e, Component & c) {
	std::vector<Component *> comps;

	if (entities.find(e) == entities.end()) { // cl� n'existe pas
		comps.push_back(&c);
		entities.insert(std::make_pair(e, comps));
	}
	else {
		comps = entities.at(e);
		comps.push_back(&c);
		entities.at(e) = comps;
	}
}

void EntityPool::remove(uint32_t e) {
	entities.erase(e);
}

void EntityPool::remove(uint32_t e, Component & c) {
	std::vector<Component *> comps;

	if (entities.find(e) != entities.end()) { // cle existe
		comps = entities.at(e);
		for (auto it = comps.begin(); it != comps.end(); it++) {
			if ((*it)->getName() == c.getName()) {
				comps.erase(it);
				break;
			}
		}
	}
}

std::vector<Component *> EntityPool::getComponents(uint32_t e) const {
	std::vector<Component *> comps;
	comps = entities.at(e);
	return comps;
}