#ifndef COMPONENT_POSITION_H
#define COMPONENT_POSITION_H

#include "Component/component.h"
#include "vector2.h"

namespace Components
{
    class Position : public Component
    {
    private:
        Vector2<int> position;

    public:
        Position();
        Position(Vector2<int> position);
        ~Position() override;

        void setPosition(Vector2<int> position);
        Vector2<int> getPosition();
        void moveTo(Vector2<int> direction, float speed);
    };
}

#endif // COMPONENT_POSITION_H