#include "Text.h"

DreamEngine::Text::Text(TextDefinition textDefinition)
	:Drawable(textDefinition), textDefinition(textDefinition), window(textDefinition.window)
{
	
}


DreamEngine::Text::~Text()
{
}

void DreamEngine::Text::setFont(Font font)
{
	text->setFont(*font.get());
}

void DreamEngine::Text::setText(std::string text)
{
	this->text->setString(text);
}

void DreamEngine::Text::setPosition(sf::Vector2f position)
{
	text->setPosition(position);
}

void DreamEngine::Text::setWorldPosition(b2Vec2 position)
{
	text->setPosition(Engine::worldToPixel(position));
}

void DreamEngine::Text::setColor(sf::Color color)
{
	text->setFillColor(color);
}

void DreamEngine::Text::setSize(int size)
{
	text->setCharacterSize(size);
}

void DreamEngine::Text::draw()
{
	window->getWindow()->draw(*text);
}

void DreamEngine::Text::onDestroy()
{
}

void DreamEngine::Text::load()
{
	text->setPosition(textDefinition.position);
	text->setFillColor(textDefinition.color);
	text->setString(textDefinition.txt);
	text->setCharacterSize(textDefinition.size);
	if (textDefinition.font != nullptr) {
		textDefinition.font->load();
		text->setFont(*textDefinition.font->get());
	}
	else {
		FontDefinition fontDef;
		Font font(fontDef);
		font.load();
		text->setFont(*font.get());
	}
}

DreamEngine::ObjectData DreamEngine::Text::save()
{
	return ObjectData();
}
