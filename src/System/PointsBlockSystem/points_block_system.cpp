#include "points_block_system.h"
#include "Component/points.h"
#include "Component/Sprite.h"
#include "Entity/entity.h"

using namespace Components;

PointsBlockSystem::PointsBlockSystem() {
    cinquante = { 0, 0, 30, 14 };
    soixante = { 32, 0, 30, 14 };
    soixante_dix = { 64, 0, 30, 14 };
    quatre_vingt = { 96, 0, 30, 14 };
    quatre_vingt_dix = { 128, 0, 30, 14 };
    cent = { 160, 0, 30, 14 };
    cent_dix = { 0, 16, 30, 14 };
    cent_vingt = { 32, 16, 30, 14 };
}

void PointsBlockSystem::update(double deltaTime) {
    System::update(deltaTime);

    EntityManager * manager = current->getManager();

    for (auto entity : manager->get()) {
        Points * p = entity->get<Points>("points");
        Sprite * s = entity->get<Sprite>("sprite");
        if (!p || !s) continue;
        switch (p->points) {
        case 50:
            s->src = cinquante;
            break;

        case 60:
            s->src = soixante;
            break;

        case 70:
            s->src = soixante_dix;
            break;

        case 80:
            s->src = quatre_vingt;
            break;

        case 90:
            s->src = quatre_vingt_dix;
            break;

        case 100:
            s->src = cent;
            break;

        case 110:
            s->src = cent_dix;
            break;

        case 120:
            s->src = cent_vingt;
            break;

        default: break;
        }
    }
}