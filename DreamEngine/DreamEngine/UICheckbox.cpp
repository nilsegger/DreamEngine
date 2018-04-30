#include "UICheckbox.h"

DreamEngine::UserInterface::Checkbox::Checkbox(CheckboxDef def)
	:UIElement(def), size(def.size),labelText(def.labelText), labelOffset(def.labelOffset), checked(def.checked)
{
}

void DreamEngine::UserInterface::Checkbox::draw()
{
	box->setPosition(position);
	text->setPosition(position + sf::Vector2f{ labelOffset + size.x, 0.f });

	box->setPosition(position);
	window->getWindow()->draw(*box);
	text->draw();
}

void DreamEngine::UserInterface::Checkbox::onDestroy()
{
	delete box;
	box = nullptr;
}

void DreamEngine::UserInterface::Checkbox::load()
{
	box = new sf::RectangleShape;
	box->setFillColor(sf::Color::Transparent);
	box->setOutlineColor(sf::Color::White);
	box->setOutlineThickness(2.f);
	box->setSize(size);

	font = new Font(FontDef());
	TextDef textDef;
	textDef.font = font;
	textDef.txt = labelText;
	textDef.position = position + sf::Vector2f{size.x, 0.f};
	textDef.window = window;
	textDef.fontSize = int(size.y - 3);
	text = new Text(textDef);
	text->load();
}

DreamEngine::ObjectData DreamEngine::UserInterface::Checkbox::save()
{
	return DreamEngine::ObjectData();
}

sf::Vector2f DreamEngine::UserInterface::Checkbox::getBounds()
{
	return size + sf::Vector2f{ labelOffset + text->getText()->getLocalBounds().width,text->getText()->getLocalBounds().height};
}

sf::Vector2f DreamEngine::UserInterface::Checkbox::getPosition()
{
	return position;
}

void DreamEngine::UserInterface::Checkbox::setPosition(sf::Vector2f absolutePos)
{
	position = absolutePos;
}

void DreamEngine::UserInterface::Checkbox::onClickBegin()
{
	checked = !checked;

	if (checked) {
		box->setFillColor(sf::Color::White);
		box->setOutlineColor(sf::Color::Black);
	}
	else {
		box->setFillColor(sf::Color::Transparent);
		box->setOutlineColor(sf::Color::White);
	}
}

void DreamEngine::UserInterface::Checkbox::onClickEnd()
{
}

void DreamEngine::UserInterface::Checkbox::onHover()
{
	box->setOutlineColor(sf::Color::Black);
}

void DreamEngine::UserInterface::Checkbox::onHoverEnd()
{
	box->setOutlineColor(sf::Color::White);
}

bool DreamEngine::UserInterface::Checkbox::isChecked()
{
	return checked;
}
