#include "text.h"

Text::Text(Entity id, EntityPool * pool, std::string text)
	: id(id), pool(pool)
{
	this->text = new TextComponent(id, text);
	transform = new TransformComponent(id);
	type = new TypeComponent(id, "text");

	pool->add(id, *this->text);
	pool->add(id, *transform);
	pool->add(id, *type);
}

Text::~Text() {
	pool->remove(id);
}