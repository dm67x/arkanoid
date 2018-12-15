#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "singleton.h"
#include "scene.h"
#include <map>

class SceneManager : public Singleton<SceneManager>
{
private:
	std::map<std::string, Scene *> scenes;
	Scene * current;

public:
	void add(Scene & s);
	void remove(const std::string name);
	void load(const std::string name);
	void clean();

	inline Scene * getCurrent() const { return current; }
};

#endif