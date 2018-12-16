#ifndef LEVEL_H
#define LEVEL_H

#include "Entity/Brick/brick.h"
#include "Board/board.h"
#include <string>
#include <vector>

class Level 
{
private:
	Board * board;
	std::vector<Entities::Brick *> bricks;
	static unsigned int next_id;
	unsigned int id;

public:
	Level(std::string filename);
	~Level();

	void load();
	void unload();
	
	inline const std::vector<Entities::Brick *> getBricks() { return bricks; }
	inline const getID() { return id; }
};
 
#endif
