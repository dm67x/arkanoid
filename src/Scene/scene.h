#ifndef SCENE_H
#define SCENE_H

#include "Window/window.h"
#include "EntityManager/entity_manager.h"
#include "EventManager/event_manager.h"
#include <string>
#include <vector>

class System;

class Scene
{
private:
	std::string name;
	int width, height;

protected:
	Scene(const std::string name);

	std::vector<System *> systems;
	static EventManager * event_manager;
	EntityManager * entity_manager;

public:
	virtual ~Scene();
	virtual void load() = 0;
	virtual void update(double deltaTime);
	virtual void draw(SDL_Surface & surface);
	virtual void input(SDL_Event e);
	void setSize(int w, int h);

	inline const std::string getName() const { return name; }
	inline const int getWidth() const { return width; }
	inline const int getHeight() const { return height; }
	inline EntityManager * getManager() { return entity_manager; }
};

#endif