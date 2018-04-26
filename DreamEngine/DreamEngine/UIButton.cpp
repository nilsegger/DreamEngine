#include "UIButton.h"

DreamEngine::UserInterface::Button::Button(ButtonDef def)
	:UIElement(def), onClickFunc(def.onClickFunc), fontSize(def.fontSize), buttonText(def.text)
{
	//(*onClickFunc)(this); Calling pointer func
}

void DreamEngine::UserInterface::Button::draw()
{

	text->setPosition(position + sf::Vector2f{ padding, padding });
	background->setPosition(position);
	bottomBorder->setPosition(position + sf::Vector2f(0.f, size.y));

	window->getWindow()->draw(*background);
	window->getWindow()->draw(*bottomBorder);
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

	size = sf::Vector2f{ text->getText()->getLocalBounds().width,text->getText()->getLocalBounds().height } +sf::Vector2f{ padding*4.f,padding*4.f };

	background = new sf::RectangleShape;
	background->setSize(size);
	background->setFillColor(CLR_BUTTON_BG);

	bottomBorder = new sf::RectangleShape;
	bottomBorder->setSize(sf::Vector2f(size.x, bottomBorderHeight));
	bottomBorder->setFillColor(CLR_BUTTON_BORDERBOTTOM);
	//background->setB
}

DreamEngine::ObjectData DreamEngine::UserInterface::Button::save()
{
	return DreamEngine::ObjectData();
}

sf::Vector2f DreamEngine::UserInterface::Button::getBounds()
{
	return size + sf::Vector2f{0.f, bottomBorderHeight};
}

void DreamEngine::UserInterface::Button::setPosition(sf::Vector2f absolutePos)
{
	position = absolutePos;
}

sf::Vector2f DreamEngine::UserInterface::Button::getPosition()
{
	return position;
}

void DreamEngine::UserInterface::Button::onClickBegin()
{
	std::cout << "Click begin" << std::endl;
	if(onClickFunc != nullptr) onClickFunc(this);
}

void DreamEngine::UserInterface::Button::onClickEnd()
{
	std::cout << "Click End" << std::endl;

}

void DreamEngine::UserInterface::Button::onHover()
{
	background->setFillColor(CLR_BUTTON_BG_HOVER);
}

void DreamEngine::UserInterface::Button::onHoverEnd()
{
	background->setFillColor(CLR_BUTTON_BG);
}
