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

public:
	Level(std::string filename);
	~Level();
	
	inline const std::vector<Entities::Brick *> getBricks() { return bricks; }
};
 
#endif
