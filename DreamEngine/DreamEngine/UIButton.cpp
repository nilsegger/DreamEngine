#include "UIButton.h"

DreamEngine::UserInterface::Button::Button(ButtonDef def)
	:UIElement(def), /*onClickFunc(def.onClickFunc),*/ fontSize(def.fontSize), buttonText(def.text)
{
	//(*onClickFunc)(this); Calling pointer func
}

void DreamEngine::UserInterface::Button::draw()
{

	text->setPosition(position + sf::Vector2f{ padding, padding });
	background->setPosition(position);

	window->getWindow()->draw(*background);
	text->draw();
}

void DreamEngine::UserInterface::Button::onDestroy()
{
	delete font;
	delete text;
	delete background;
}

void DreamEngine::UserInterface::Button::load()
{
	FontDef fontDef;
	fontDef.type = "Button Font";
	font = new Font(fontDef);
	TextDef textDef;
	textDef.window = window;
	textDef.color = CLR_BUTTON_TEXT;
	textDef.font = font;
	//textDef.position = position + sf::Vector2f{padding, padding};
	textDef.fontSize = fontSize;
	textDef.txt = buttonText;
	textDef.type = "Button Text";
	text = new Text(textDef);
	text->load();

	std::cout << text->getText()->getLocalBounds().width << std::endl;

	size = sf::Vector2f{ text->getText()->getLocalBounds().width,text->getText()->getLocalBounds().height } +sf::Vector2f{ padding*2.f,padding*2.f };

	background = new sf::RectangleShape;
	background->setSize(size + sf::Vector2f{padding*2.f, padding*2.f});
	background->setFillColor(CLR_BUTTON_BG);
	background->setB
}

DreamEngine::ObjectData DreamEngine::UserInterface::Button::save()
{
	return DreamEngine::ObjectData();
}

sf::Vector2f DreamEngine::UserInterface::Button::getBounds()
{
	return sf::Vector2f();
}

void DreamEngine::UserInterface::Button::setPosition(sf::Vector2f absolutePos)
{
	position = absolutePos;
}
