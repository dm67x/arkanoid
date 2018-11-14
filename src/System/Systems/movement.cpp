#include "movement.h"
#include "Component/Components/position.h"
#include "Component/Components/velocity.h"

using namespace Systems;

Movement::Movement() {
}

Movement::~Movement() {
}

void Movement::update(float dt) {
    Entity * entity;
    Components::Velocity * v = nullptr;
    Components::Position * p = nullptr;

    for (auto e : entity_pool->getAll()) {
        entity = e.second.get();
        for (auto c : entity->getComponents()) {
            if (c.get()->getName() == "velocity") {
                v = dynamic_cast<Components::Velocity *>(c.get());
            }

            if (c.get()->getName() == "position") {
                p = dynamic_cast<Components::Position *>(c.get());
            }
        }

        if (v && p)
            p->set(p->get().x + v->getVelocity().x, p->get().y + v->getVelocity().y);

        v = nullptr;
        p = nullptr;
    }
}

void Movement::draw(SDL_Surface & surface) {
    // Nothing to do
}
