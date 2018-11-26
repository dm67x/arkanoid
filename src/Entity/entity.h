#ifndef ENTITY_H
#define ENTITY_H

#include "vector2.h"
#include <SDL.h>
#include <string>

class Entity
{
private:
    std::string name;
    Vector2<int> position;
    SDL_Rect graphic;

    int id;
    static int next_id;

protected:
    Entity(const std::string name);

public:
    virtual ~Entity();
    virtual std::string getType() = 0;

    void setPosition(Vector2<int> v);
    void setGraphic(SDL_Rect rect);
    inline Vector2<int> getPosition() const { return position; }
    inline SDL_Rect getGraphic() const { return graphic; }
    inline int getID() const { return id; }

    SDL_Rect getBoundingBox();
    bool collideWith(Entity & e);
};

#endif