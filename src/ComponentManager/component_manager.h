#ifndef COMPONENT_MANAGER_H
#define COMPONENT_MANAGER_H

#include "Component/transform.h"
#include "Component/motion.h"
#include "Component/collision.h"
#include "Component/sprite.h"
#include "Component/health.h"
#include "Component/control.h"
#include "Entity/entity.h"
#include "singleton.h"
#include <map>

class ComponentManager : Singleton<ComponentManager>
{
private:
    std::map<Entity, Components::Transform *> transforms;
    std::map<Entity, Components::Motion *> motions;
    std::map<Entity, Components::Collision *> collisions;
    std::map<Entity, Components::Sprite *> sprites;
    std::map<Entity, Components::Health *> healths;
    std::map<Entity, Components::Control *> controls;

public:
    ComponentManager();
    ~ComponentManager();

    Component * createComponent(Entity e, std::string type);
    void removeComponents(Entity e);
    void removeComponent(Entity e, std::string type);

    inline const std::map<Entity, Components::Transform *> getTransforms() { return transforms; }
    inline const std::map<Entity, Components::Motion *> getMotions() { return motions; }
    inline const std::map<Entity, Components::Collision *> getCollisions() { return collisions; }
    inline const std::map<Entity, Components::Sprite *> getSprites() { return sprites; }
    inline const std::map<Entity, Components::Health *> getHealths() { return healths; }
    inline const std::map<Entity, Components::Control *> getControls() { return controls; }
};

#endif