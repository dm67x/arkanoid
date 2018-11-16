#ifndef SYSTEM_COLLISION_H
#define SYSTEM_COLLISION_H

#include "System/system.h"

namespace Systems
{

	class Collision : public System
	{

	public:
		Collision();
		~Collision();

		void update(double dt) override;
		void draw(SDL_Surface & surface) override;

	};

}

#endif // SYSTEM_COLLISION_H