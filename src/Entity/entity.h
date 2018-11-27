#ifndef ENTITY_H
#define ENTITY_H

#include "vector2.h"
#include <SDL.h>
#include <string>
#include "EventManager/event_manager.h"

class Entity
{
private:
    std::string name;
    Vector2<int> position;
    SDL_Rect graphic;

    int id;
    static int next_id;

protected:
    static EventManager * event_manager;

    Entity(const std::string name);

public:
    virtual ~Entity();
    virtual std::string getType() = 0;
    virtual void move() = 0;
    virtual void setDirection(Vector2<int> direction) = 0;
    virtual Vector2<int> getDirection() const = 0;

    void setPosition(Vector2<int> v);
    void setGraphic(SDL_Rect rect);
    inline Vector2<int> getPosition() const { return position; }
    inline SDL_Rect getGraphic() const { return graphic; }
    inline int getID() const { return id; }

    SDL_Rect getBoundingBox();
    bool collideWith(Entity & e);
};

#endif