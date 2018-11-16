/**
  * @file entity.h
  * @version 1
  */

#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include "vector2.h"
#include <SDL.h>

/**
 * @brief La classe entité (mère de toutes les autres classes entités)
 */
class Entity
{

private:
    std::string _name;
    Vector2<int> _position;

protected:
    Entity(std::string _name);
    Entity(std::string _name, Vector2<int> _position);

    SDL_Rect _src_rect;

public:
    virtual ~Entity();

    void setPosition(Vector2<int> _position);
    Vector2<int> getPosition();

    std::string getName();
    SDL_Rect getRect();

    bool collideWith(Entity & e);

};

#endif // ENTITY_H
