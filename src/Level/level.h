#ifndef LEVEL_H
#define LEVEL_H

#include "EntityManager/entity_manager.h"
#include "Board/board.h"
#include <string>

class Level 
{
private:
	EntityManager * manager;
	Board * board;
	
public:
	Level(std::string filename);
	~Level();
	
	inline EntityManager * getManager() { return manager; }
};
 
#endif
