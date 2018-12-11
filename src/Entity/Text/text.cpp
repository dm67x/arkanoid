#include "text.h"

Text::Text(uint32_t id, EntityPool * pool, std::string text)
	: Entity(id, pool, "text")
{
	this->text = new TextComponent(text);
	pool->add(id, *this->text);
}