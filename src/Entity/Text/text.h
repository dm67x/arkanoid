#ifndef TEXT_H
#define TEXT_H

#include "Entity/entity.h"
#include "Entity/entity_pool.h"
#include "Component/text_component.h"
#include "Component/transform_component.h"
#include "Component/type_component.h"

class Text
{
private:
	Entity id;
	EntityPool * pool;

public:
	Text(Entity id, EntityPool * pool, std::string text);
	~Text();

	TextComponent * text;
	TransformComponent * transform;
	TypeComponent * type;
};

#endif