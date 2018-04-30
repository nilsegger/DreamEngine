#include "UITextInput.h"

DreamEngine::UserInterface::TextInput::TextInput(TextInputDef def)
	:UIElement(def), fontSize(def.fontSize), maxWidth(def.maxWidth), textPadding(def.textPadding)
{
}

void DreamEngine::UserInterface::TextInput::draw()
{

	addText(window->getTextEnteredDrawCycle());
	
	label->setPosition(position);

	text->setPosition(position + sf::Vector2f{ textPadding, textPadding } +sf::Vector2f{label->getText()->getLocalBounds().width, 0.f});
	

	size = { text->getText()->getLocalBounds().width + 2.f*textPadding,fontSize + 2.f*textPadding };

	background->setSize(size);
	background->setPosition(position + sf::Vector2f{ label->getText()->getLocalBounds().width, 0.f });

	label->draw();
	window->getWindow()->draw(*background);
	text->draw();
}

void DreamEngine::UserInterface::TextInput::onDestroy()
{
}

void DreamEngine::UserInterface::TextInput::load()
{
	background = new sf::RectangleShape;
	
	background->setFillColor(sf::Color::White);

	font = new Font(FontDef());
	TextDef textDef;
	textDef.fontSize = fontSize;
	textDef.font = font;
	textDef.txt = "Click to enter text..";
	textDef.color = sf::Color::Black;
	textDef.window = window;
	text = new Text(textDef);
	text->load();

	textDef.color = sf::Color::White;
	textDef.txt = "Tree name:";
	label = new Text(textDef);
	label->load();
}

DreamEngine::ObjectData DreamEngine::UserInterface::TextInput::save()
{
	return DreamEngine::ObjectData();
}

sf::Vector2f DreamEngine::UserInterface::TextInput::getBounds()
{
	return size + sf::Vector2f{ label->getText()->getLocalBounds().width, 0.f };
}

sf::Vector2f DreamEngine::UserInterface::TextInput::getPosition()
{
	return position;
}

void DreamEngine::UserInterface::TextInput::setPosition(sf::Vector2f absolutePos)
{
	position = absolutePos;
}

void DreamEngine::UserInterface::TextInput::onClickBegin()
{
}

void DreamEngine::UserInterface::TextInput::onClickEnd()
{
}

void DreamEngine::UserInterface::TextInput::onHover()
{
}

void DreamEngine::UserInterface::TextInput::onHoverEnd()
{
}

void DreamEngine::UserInterface::TextInput::addText(std::string txt)
{

	if (focused == false) return;

	if (txt != "") {
		if (empty) {
			enteredText = txt;
			empty = false;
		}
		else {
			enteredText += txt;
		}
	}

	for (int i = window->getKeys(); i; i = window->getKeys()) {
		switch (i)
		{
		case 59: //backspace
			enteredText = enteredText.substr(0, enteredText.size() - 2);
			break;
		default:
			break;
		}
	}

	text->setText(enteredText);
	

	

}

void DreamEngine::UserInterface::TextInput::onFocus()
{
	std::cout << "Focus gained" << std::endl;
	focused = true;
}

void DreamEngine::UserInterface::TextInput::onFocusLost()
{
	focused = false;
	std::cout << "Focus lost" << std::endl;
}
