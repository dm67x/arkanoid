#include "entity_factory.h"
#include "Entity/Ship/ship.h"
#include "Entity/Brick/brick.h"
#include "Entity/Ball/ball.h"
#include "Entity/Text/text.h"

Entity * EntityFactory::build(std::string type) {
    Entity * entity = nullptr;
    
    if (type == "brick") entity = new Entities::Brick(50);
    else if (type == "ship") entity = new Entities::Ship();
    else if (type == "ball") entity = new Entities::Ball();
	else if (type == "text") entity = new Entities::Text("");
    return entity;
}