#ifndef TEXT_H
#define TEXT_H

#include "Entity/entity.h"
#include "Component/text_component.h"

class Text : public Entity
{
public:
	Text(uint32_t id, EntityPool * pool, std::string text);

	TextComponent * text;
};

#endif