#include "entity.h"

int Entity::next_id = 0;
EventManager * Entity::event_manager = Singleton<EventManager>::getInstance();

Entity::Entity(const std::string name) {
    this->name = name;
    this->id = next_id++;
}

Entity::~Entity() {
}

void Entity::setPosition(Vector2<float> v) {
    position = v;
}

void Entity::setGraphic(SDL_Rect rect) {
    graphic = rect;
}

SDL_Rect Entity::getBoundingBox() {
    return { 
        static_cast<int>(position.x - graphic.w / 2.0f), 
		static_cast<int>(position.y - graphic.h / 2.0f),
		static_cast<int>(position.x + graphic.w / 2.0f),
		static_cast<int>(position.y + graphic.h / 2.0f)
    };
}

bool Entity::collideWith(Entity & e) {
    SDL_Rect bounding_e, bounding;
    bounding = getBoundingBox();
    bounding_e = e.getBoundingBox();

    return (bounding_e.w > bounding.x
            && bounding_e.h > bounding.y
            && bounding_e.x < bounding.w
            && bounding_e.y < bounding.h);
}