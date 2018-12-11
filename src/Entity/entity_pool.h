#ifndef ENTITY_POOL_H
#define ENTITY_POOL_H

#include <map>
#include <vector>

#include "Component/component.h"

class EntityPool
{
private:
	std::map<uint32_t, std::vector<Component *>> entities;

public:
	EntityPool();
	~EntityPool();

	void add(uint32_t e, Component & c);
	void remove(uint32_t e);
	void remove(uint32_t e, Component & c);

	inline std::map<uint32_t, std::vector<Component *>> getEntities() const {
		return entities;
	}

	std::vector<Component *> getComponents(uint32_t e) const;
};

#endif