#include "Font.h"

DreamEngine::Font::Font(FontDefinition fontDefinition)
	:Object(fontDefinition), path(fontDefinition.path)
{
	font = new sf::Font;
}

DreamEngine::Font::~Font()
{
	if(font != nullptr) delete font;
	font = nullptr;
}

bool DreamEngine::Font::load()
{
	if (font->loadFromFile(path)) return true;
	if (font->loadFromFile(defaultFont)) {
		std::cout << ("Loading default font instead of '" + path + "'") << std::endl;
		return true;
	}
	return false;
}

sf::Font * DreamEngine::Font::get()
{
	return font;
}
