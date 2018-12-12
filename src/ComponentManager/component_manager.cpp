#include "component_manager.h"
#include "EventManager/event_manager.h"

ComponentManager::ComponentManager() {
}

ComponentManager::~ComponentManager() {
    for (auto c : transforms) delete c.second;
    for (auto c : motions) delete c.second;
    for (auto c : collisions) delete c.second;
    for (auto c : sprites) delete c.second;
    for (auto c : healths) delete c.second;
    for (auto c : controls) delete c.second;

    transforms.clear();
    motions.clear();
    collisions.clear();
    sprites.clear();
    healths.clear();
    controls.clear();
}

Component * ComponentManager::createComponent(Entity e, std::string type) {
    Component * c = nullptr;
    
    if (type == "transform") {
        c = new Components::Transform();
        transforms.insert(std::make_pair(e, static_cast<Components::Transform *>(c)));
    } else if (type == "motion") {
        c = new Components::Motion();
        motions.insert(std::make_pair(e, static_cast<Components::Motion *>(c)));
    } else if (type == "collision") {
        c = new Components::Collision();
        collisions.insert(std::make_pair(e, static_cast<Components::Collision *>(c)));
    } else if (type == "sprite") {
        c = new Components::Sprite();
        sprites.insert(std::make_pair(e, static_cast<Components::Sprite *>(c)));
    } else if (type == "health") {
        c = new Components::Health();
        healths.insert(std::make_pair(e, static_cast<Components::Health *>(c)));
    } else if (type == "control") {
        c = new Components::Control();
        controls.insert(std::make_pair(e, static_cast<Components::Control *>(c)));
    } else if (type == "points") {
        c = new Components::Points();
        points.insert(std::make_pair(e, static_cast<Components::Points *>(c)));
    }

    return c;
}

void ComponentManager::removeComponent(Entity e, std::string type) {
    try {
        if (type == "transform") {
            delete transforms.at(e);
            transforms.erase(e);
        } else if (type == "motion") {
            delete motions.at(e);
            motions.erase(e);
        } else if (type == "collision") {
            delete collisions.at(e);
            collisions.erase(e);
        } else if (type == "sprite") {
            delete sprites.at(e);
            sprites.erase(e);
        } else if (type == "health") {
            delete healths.at(e);
            healths.erase(e);
        } else if (type == "control") {
            delete controls.at(e);
            controls.erase(e);
        } else if (type == "points") {
            delete points.at(e);
            points.erase(e);
        }
    } catch (std::out_of_range) {
    }
}

void ComponentManager::removeComponents(Entity e) {
    removeComponent(e, "transform");
    removeComponent(e, "motion");
    removeComponent(e, "collision");
    removeComponent(e, "sprite");
    removeComponent(e, "health");
    removeComponent(e, "control");
}