#ifndef SCENE_H
#define SCENE_H

#include "Window/window.h"
#include "EventManager/event_manager.h"
#include <string>
#include <vector>

class System;
class SystemManager;

class Scene
{
private:
	std::string name;
	int width, height;

protected:
	Scene(const std::string name);
	SystemManager * system_manager;

	static EventManager * event_manager;

public:
	virtual ~Scene();
	virtual void load() = 0;
	virtual void unload() = 0;
	virtual void update(double deltaTime);
	virtual void draw(SDL_Surface & surface);
	virtual void input(SDL_Event e);
	void setSize(int w, int h);

	inline const std::string getName() const { return name; }
	inline const int getWidth() const { return width; }
	inline const int getHeight() const { return height; }
};

#endif