#ifndef TRANSITION_SCENE_H
#define TRANSITION_SCENE_H

#include "Scene/scene.h"

namespace Scenes
{
	class TransitionScene : public Scene
	{
	private:
		float duration;
		float duration_div, tmp_duration;
		bool nb; // noir à blanc
		const std::string transition;
		SDL_Color color;

	public:
		TransitionScene(const std::string transition, float duration);
		~TransitionScene() override;

		void load() override;
		void update(float deltaTime) override;
		void draw(SDL_Surface & surface) override;
		void input(SDL_Event e) override;
	};
}

#endif