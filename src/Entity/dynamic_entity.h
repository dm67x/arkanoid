#ifndef DYNAMIC_ENTITY_H
#define DYNAMIC_ENTITY_H

#include "entity.h"

class DynamicEntity : public Entity
{
private:
    float speed;
    Vector2<float> direction;
	bool can_move;

protected:
    DynamicEntity(const std::string name) : Entity(name), can_move(true) {}

public:
    virtual ~DynamicEntity() {}
    virtual std::string getType() = 0;
    void setDirection(Vector2<float> direction) override;

    inline void setSpeed(float s) { speed = s; }
    inline float getSpeed() const { return speed; }
    inline Vector2<float> getDirection() const override { return direction; }

	inline void setMovable(bool m) { can_move = m; }
	inline bool canMove() const { return can_move; }
};

#endif