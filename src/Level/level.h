#ifndef LEVEL_H
#define LEVEL_H

#include "EntityManager/entity_manager.h"
#include <string>

class Level 
{
private:
	EntityManager * manager;
	
public:
	Level(std::string filename);
	~Level();
	
	inline EntityManager * getManager() { return manager; }
};
 
#endif
