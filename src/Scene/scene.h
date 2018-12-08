#ifndef SCENE_H
#define SCENE_H

#include "Entity/entity.h"
#include "Window/window.h"
#include "Entity/entity_pool.h"

#include <string>
#include <vector>

class System;
class EventManager;

class Scene
{
private:
	std::string name;
	int width, height;

protected:
	Scene(const std::string name);

	std::vector<System *> systems;
	static EventManager * event_manager;
	EntityPool * pool;

public:
	virtual ~Scene();
	virtual void load() = 0;
	virtual void update(float deltaTime) = 0;
	virtual void draw(SDL_Surface & surface) = 0;
	virtual void input(SDL_Event e) = 0;

	void setSize(int w, int h);

	inline const std::string getName() const { return name; }
	inline const int getWidth() const { return width; }
	inline const int getHeight() const { return height; }
	inline EntityPool * getPool() const { return pool; }
};

#endif