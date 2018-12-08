#ifndef ENTITY_POOL_H
#define ENTITY_POOL_H

#include <map>
#include <vector>

#include "entity.h"
#include "Component/component.h"

class EntityPool
{
private:
	std::map<Entity, std::vector<Component *>> entities;

public:
	EntityPool();
	~EntityPool();

	void add(Entity e, Component & c);
	void remove(Entity e);
	void remove(Entity e, Component & c);

	inline std::map<Entity, std::vector<Component *>> getEntities() const {
		return entities;
	}

	std::vector<Component *> getComponents(Entity e) const;
};

#endif