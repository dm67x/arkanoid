#include "collision_system.h"
#include "Entity/entity.h"
#include "Component/transform.h"
#include "Component/sprite.h"
#include "Component/motion.h"
#include "Component/health.h"

void CollisionSystem::update(double deltaTime) {
    if (!current_scene) return;
    EntityManager * entity_manager = current_scene->getEntityManager();

    for (auto entity : entity_manager->get()) {
        Components::Transform * tc = static_cast<Components::Transform *>(entity->get("transform"));
        Components::Sprite * sc = static_cast<Components::Sprite *>(entity->get("sprite"));
        Components::Motion * mc = static_cast<Components::Motion *>(entity->get("motion"));

        if (!mc || !sc || !tc || entity->get("collision")) continue;

        for (auto entity2 : entity_manager->get()) {
            if (entity == entity2) continue;
            Components::Transform * tc2 = static_cast<Components::Transform *>(entity2->get("transform"));
            Components::Sprite * sc2 = static_cast<Components::Sprite *>(entity2->get("sprite"));
            Components::Health * hc = static_cast<Components::Health *>(entity2->get("health"));

            if (!sc2 || !tc2 || entity->get("collision")) continue;

            // prevision de collision au prochain frame
            Vector2<float> next_position = Vector2<float>(
                tc->position.x + mc->velocity.x * deltaTime * 60.0f,
                tc->position.y + mc->velocity.y * deltaTime * 60.0f
            );
        
            SDL_Rect box1, box2, nbox1;
            box1.x = static_cast<int>(next_position.x - (sc->src.w / 2) * tc->scale.x);
            box1.y = static_cast<int>(next_position.y - (sc->src.h / 2) * tc->scale.y);
            box1.w = static_cast<int>(next_position.x + (sc->src.w / 2) * tc->scale.x);
            box1.h = static_cast<int>(next_position.y + (sc->src.h / 2) * tc->scale.y);

            box2.x = static_cast<int>(tc2->position.x - (sc2->src.w / 2) * tc2->scale.x);
            box2.y = static_cast<int>(tc2->position.y - (sc2->src.h / 2) * tc2->scale.y);
            box2.w = static_cast<int>(tc2->position.x + (sc2->src.w / 2) * tc2->scale.x);
            box2.h = static_cast<int>(tc2->position.y + (sc2->src.h / 2) * tc2->scale.y);

            if (box1.x <= box2.w && box1.w >= box2.x 
                && box1.y <= box2.h && box1.h >= box2.y) 
            {
                if (hc) {
                    hc->life--;
                    if (hc->life <= 0) {
                        event_manager->trigger("destroy_entity", &entity2);
                    }
                }

                SDL_Log("collision");
                if (box1.y <= box2.h && box1.h >= box2.h) { // balle tape le bas
                    mc->velocity.y *= -1;
                    //tc->position.y = box2.h + (sc->src.h / 2) * tc->scale.y;
                } else if (box1.y <= box2.y && box1.h >= box2.y) { // balle tape le haut
                    mc->velocity.y *= -1;
                    //tc->position.y = box2.y - (sc->src.h / 2) * tc->scale.y;
                } 
                
                if (box1.w >= box2.x && box1.x <= box2.x) { // balle tape à gauche
                    mc->velocity.x *= -1;
                    //tc->position.x = box2.x - (sc2->src.w / 2) * tc2->scale.x;
                } else if (box1.x <= box2.w && box1.w >= box2.w) { // balle tape à droite
                    mc->velocity.x *= -1;
                    //tc->position.x = box2.w + (sc2->src.w / 2) * tc2->scale.x;
                }
            }
        }
    }
}