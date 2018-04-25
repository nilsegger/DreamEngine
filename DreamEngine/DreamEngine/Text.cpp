#include "Text.h"

DreamEngine::Text::Text(TextDef textDefinition)
	:Drawable(textDefinition), textDefinition(textDefinition), window(textDefinition.window)
{
	
}


DreamEngine::Text::~Text()
{
	if (text != nullptr) delete text;
	text = nullptr;
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

void DreamEngine::Text::setSize(int fontSize)
{
	text->setCharacterSize(fontSize);
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
	text->setCharacterSize(textDefinition.fontSize);
	if (textDefinition.font != nullptr) {
		textDefinition.font->load();
		text->setFont(*textDefinition.font->get());
	}
	else {
		FontDef fontDef;
		Font font(fontDef);
		font.load();
		text->setFont(*font.get());
	}
}

DreamEngine::ObjectData DreamEngine::Text::save()
{
	return ObjectData();
}

sf::Text * DreamEngine::Text::getText()
{
	return text;
}
