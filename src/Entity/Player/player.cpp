#include "player.h"
#include "Component/ball_number.h"
#include "Component/transform.h"

using namespace Entities;

Player::Player(const std::string name, Vector2<float> position, EntityManager * manager) 
    : Entity(manager), name(name)
{
    // Creation de l'entite "ship"
	ship = new Entities::Ship(manager);
    Components::Transform * tc = ship->get<Components::Transform>("transform");
	tc->position = position;

    // Creation de l'entité balle
	Entities::Ball * ball = new Entities::Ball(manager);
    Components::Transform * ball_tc = ball->get<Components::Transform>("transform");
	ball_tc->position = Vector2<float>(position.x, position.y - 30.0f);
    balls.push_back(ball);

    // Creation du composant nombre de balles
    Components::BallNumber * nb_ball = new Components::BallNumber();
    nb_ball->number = 1;
    add(nb_ball);
}

Player::~Player() {
    delete ship;
    for (auto ball : balls) delete ball;

    balls.clear();
}