#include "transition_scene.h"
#include "Scene/scene_manager.h"

using namespace Scenes;

TransitionScene::TransitionScene(const std::string transition, float duration) 
	: Scene("transition"), duration(duration), transition(transition)
{
	duration_div = duration / 2.0f;
	tmp_duration = 0;
	nb = true;
	color.r = color.g = color.b = 0;
}

TransitionScene::~TransitionScene() {
}

void TransitionScene::load() {

}

void TransitionScene::update(float deltaTime) {
	duration -= deltaTime;

	if (duration <= 0) {
		Singleton<SceneManager>::getInstance()->goTo(transition);
	}

	if (nb) {
		tmp_duration += deltaTime;
		color.r = tmp_duration * (255.0f / duration_div);
		color.g = tmp_duration * (255.0f / duration_div);
		color.b = tmp_duration * (255.0f / duration_div);
	} else {
		tmp_duration -= deltaTime;
		color.r = tmp_duration * (255.0f / duration_div);
		color.g = tmp_duration * (255.0f / duration_div);
		color.b = tmp_duration * (255.0f / duration_div);
	}

	if (tmp_duration >= duration_div && nb) {
		nb = false;
		tmp_duration = duration_div;
	}
}

void TransitionScene::draw(SDL_Surface & surface) {
	SDL_FillRect(&surface, nullptr, SDL_MapRGB(surface.format, color.r, color.g, color.b));
}

void TransitionScene::input(SDL_Event e) {

}