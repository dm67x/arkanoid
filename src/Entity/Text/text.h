#ifndef TEXT_H
#define TEXT_H

#include "Entity/static_entity.h"
#include <vector>

namespace Entities
{

	class Text : public StaticEntity
	{
	private:
		std::string text;

		SDL_Rect getGraphicFromChar(char c);

	public:
		Text(const std::string text);

		void setText(const std::string text);
		inline std::string getText() const { return text; }
		std::vector<SDL_Rect> getTextGraphics();
		std::string getType() override;
	};

}

#endif