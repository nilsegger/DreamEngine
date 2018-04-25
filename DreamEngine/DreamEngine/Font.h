#pragma once

#include "CoreObject.h"
#include <SFML\Graphics.hpp>
#include <iostream>

namespace DreamEngine {

	struct FontDef : public DreamEngine::Core::ObjectDef {
		std::string path = "Raleway.ttf";
	};

	class Font : public DreamEngine::Core::Object
	{
	public:
		Font(FontDef fontDefinition);
		~Font();
		bool load();
		sf::Font * get();

	private:
		const std::string defaultFont = "Raleway.ttf";
		std::string path;
		sf::Font * font;
	};

};