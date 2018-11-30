#ifndef SCENE_H
#define SCENE_H

#include "EventManager/event_manager.h"
#include "System/system.h"
#include "Entity/entity.h"
#include "Entity/entity_factory.h"
#include <string>
#include <vector>

class Scene
{
private:
	std::string name;

protected:
	Scene(const std::string name);

	std::vector<System *> systems;
	static EventManager * event_manager;
	static EntityFactory * entity_factory;
	EntityPool * pool;

public:
	virtual ~Scene();
	virtual void load() = 0;
	virtual void update(float deltaTime) = 0;
	virtual void draw(SDL_Surface & surface) = 0;
	virtual void input(SDL_Event e) = 0;
	void reload();

	inline const std::string getName() const { return name; }
};

#endif