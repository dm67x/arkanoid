#include "entity_factory.h"
#include "Entity/Ship/ship.h"
#include "Entity/Brick/brick.h"
#include "Entity/Ball/ball.h"
#include "Entity/Text/text.h"

Entity * EntityFactory::build(std::string type) {
    if (type == "brick") 
		return new Entities::Brick();
    else if (type == "ship") 
		return new Entities::Ship();
    else if (type == "ball") 
		return new Entities::Ball();
	else if (type == "text") 
		return new Entities::Text();
    
	throw std::string("Erreur le type n'est pas reconnu");
}