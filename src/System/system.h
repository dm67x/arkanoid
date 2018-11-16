#ifndef SYSTEM_H
#define SYSTEM_H

#include "Entity/entity_factory.h"
#include <vector>
#include <SDL.h>

class System
{

protected:
	static EntityFactory * _entity_factory;

	System();
	
public:
	virtual ~System();

	virtual void update(double dt) = 0;
	virtual void draw(SDL_Surface & surface) = 0;

};

#endif // SYSTEM_H