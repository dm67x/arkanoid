#include "render.h"
#include "Component/Components/graphic.h"
#include "Component/Components/position.h"

using namespace Systems;

Render::Render() {
}

Render::~Render() {

}

void Render::update(float dt) {
    // Nothing to do
}

void Render::draw(SDL_Surface & surface) {
    Entity * entity;
    Components::Graphic * graphic_component = nullptr;
    Components::Position * position_component = nullptr;
    SDL_Rect cut, position;

    for (auto e : entity_pool->getAll()) {
        entity = e.second.get();
        for (auto c : entity->getComponents()) {
            if (c.get()->getName() == "Graphic") {
                graphic_component = dynamic_cast<Components::Graphic *>(c.get());
            }

            if (c.get()->getName() == "Position") {
                position_component = dynamic_cast<Components::Position *>(c.get());
            }
        }

        if (graphic_component && position_component) {
            cut = graphic_component->getCut();
            position = position_component->get();
            position.w = cut.w;
            position.h = cut.h;
            SDL_BlitSurface(graphic_component->getSurface(), &cut, &surface, &position);
        }

        graphic_component = nullptr;
        position_component = nullptr;
    }
}
