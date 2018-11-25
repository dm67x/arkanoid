#ifndef SYSTEM_RENDER_H
#define SYSTEM_RENDER_H

#include "System/system.h"

namespace Systems
{

	class Render : public System
	{
		
	private:
		SDL_Surface * sprite;

	public:
		Render();
		~Render();

		void update(double dt) override;
		void draw(SDL_Surface & surface) override;

	};

}

#endif // SYSTEM_RENDER_H