#include "Panel.h"

bool DreamEngine::UserInterface::Panel::panelIsBeingDragged = false;
int DreamEngine::UserInterface::Panel::lastFocused = -1;

DreamEngine::UserInterface::Panel::Panel(PanelDef def)
	:Drawable(def), size(def.size), position(def.position), mouse(window->getWindow()), title(def.panelTitle)
{
}

DreamEngine::UserInterface::Panel::~Panel()
{
	delete topbar;
	delete body;
	delete close;
}

void DreamEngine::UserInterface::Panel::draw()
{
	closeEvent();
	dragEvent();

	onElementsClickEvent();

	if(isFocused()) body->setFillColor(CLR_PANEL_FOCUSED_BG);
	else body->setFillColor(CLR_PANEL_UNFOCUSED_BG);

	close->setPosition(position + sf::Vector2f{ size.x - topbarsize*2.f, 0.f});
	topbar->setPosition(position);
	body->setPosition(position + sf::Vector2f{ 0,topbarsize }); //offset for bar

	window->getWindow()->draw(*body);
	window->getWindow()->draw(*topbar);
	window->getWindow()->draw(*close);

	text->setPosition(position);
	text->draw();//title

	for (int i = 0; i < int(elements.size()); i++) {
		elements[i]->draw();
	}
}

void DreamEngine::UserInterface::Panel::onDestroy()
{
	delete body;
	delete topbar;
	delete close;
	close = nullptr;
	body = nullptr;
	topbar = nullptr;

	for (int i = 0; i < int(elements.size()); i++) {
		elements[i]->onDestroy();
	}
}

void DreamEngine::UserInterface::Panel::load()
{
	FontDef fontDef;
	font = new Font(fontDef);
	TextDef textDef;
	textDef.fontSize = topbarsize - 3;
	textDef.txt = title;
	textDef.window = window;
	textDef.position = position;
	textDef.font = font;
	text = new Text(textDef);
	text->load();

	topbar = new sf::RectangleShape;
	topbar->setSize(sf::Vector2f{ size.x, topbarsize });
	topbar->setFillColor(CLR_PANEL_TOPBAR);

	close = new sf::RectangleShape;
	close->setSize(sf::Vector2f{ topbarsize * 2.f, topbarsize });
	close->setFillColor(CLR_PANEL_CLOSABLE);

	if (closable == false) {
		close->setFillColor(CLR_PANEL_UNCLOSABLE);
	}

	body = new sf::RectangleShape;
	body->setSize(size);
	body->setFillColor(CLR_PANEL_UNFOCUSED_BG);

	for (int i = 0; i < int(elements.size()); i++) {
		elements[i]->load();
	}
}

DreamEngine::ObjectData DreamEngine::UserInterface::Panel::save()
{

	for (int i = 0; i < int(elements.size()); i++) {
		elements[i]->save();
	}

	return ObjectData();
}

void DreamEngine::UserInterface::Panel::dragEvent()
{
	if (beingDragged == true) {
		if (mouse.leftIsClicked() == false || dragable == false) {
			beingDragged = false;
			panelIsBeingDragged = false;
			return;
		}
		position = mouse.getMouseScreenPosition() - dragOffset;
		setElementsPositions();
	}
	else {
		if (panelIsBeingDragged) return;

		if (mouse.leftIsClicked() == false) return;

		sf::Vector2f mousePos = mouse.getMouseScreenPosition();

		if (mousePos.x >= position.x && mousePos.x <= position.x + size.x - topbarsize *2.f &&
			mousePos.y >= position.y && mousePos.y <= position.y + topbarsize) {

			dragOffset = mousePos - position;

			beingDragged = true;
			panelIsBeingDragged = true;
			lastFocused = id;
		}


	}
}

void DreamEngine::UserInterface::Panel::closeEvent()
{

	if (panelIsBeingDragged || beingDragged || closed || closable == false) return;

	if (mouse.leftIsClicked() == false) return;

	sf::Vector2f mousePos = mouse.getMouseScreenPosition();

	if (mousePos.x >= position.x + size.x - topbarsize*2.f && mousePos.x <= position.x + size.x &&
		mousePos.y >= position.y && mousePos.y <= position.y + topbarsize) {
		closed = true;
		std::cout << "Closing panels is not supported yet..." << std::endl;
	}


	
}

bool DreamEngine::UserInterface::Panel::isFocused()
{
	return id == lastFocused;
}

void DreamEngine::UserInterface::Panel::addUIElement(UIElement * element, sf::Vector2f offset)
{
	elements.push_back(element);
	element->setPosition(position + offset + sf::Vector2f{0, topbarsize});
	element->offset = offset;
}

void DreamEngine::UserInterface::Panel::setElementsPositions()
{
	for (int i = 0; i < int(elements.size()); i++) {
		elements[i]->setPosition(position + elements[i]->offset + sf::Vector2f{ 0, topbarsize });
	}
}

void DreamEngine::UserInterface::Panel::onElementsClickEvent()
{
	if (isFocused() == false) return;

	for (int i = 0; i < int(elements.size()); i++) {
		
		sf::Vector2f mousePos = mouse.getMouseScreenPosition();
		
		//Box collision

		/*std::cout << "Element " << i << std::endl;
		std::cout << "Element X " << elements[i]->getPosition().x << std::endl;
		std::cout << "Element Y " << elements[i]->getPosition().y << std::endl;
		std::cout << "Element Bounds X " << elements[i]->getBounds().x << std::endl;
		std::cout << "Element Bounds Y " << elements[i]->getBounds().y << std::endl;
		std::cout << "Mouse Pos" << mousePos.x << "#" << mousePos.y << std::endl;
		Engine::waitForKeyPress();*/
		if (mousePos.x >= elements[i]->getPosition().x && mousePos.x <= elements[i]->getPosition().x + elements[i]->getBounds().x
			&&mousePos.y >= elements[i]->getPosition().y && mousePos.y <= elements[i]->getPosition().y + elements[i]->getBounds().y) {

			

			if (elements[i]->hovering == false) {
				elements[i]->hovering = true;
				elements[i]->onHover();
			}

			if (mouse.leftIsClicked()) {
				if (elements[i]->clicked == false) {
					elements[i]->clicked = true;
					elements[i]->onClickBegin();
				}
			}
			else {
				if (elements[i]->clicked) {
					elements[i]->clicked = false;
					elements[i]->onClickEnd();
				}
			}

		}
		else {
			if (elements[i]->hovering) {
				elements[i]->hovering = false;
				elements[i]->onHoverEnd();
			}
		}

		break; // only want one element clicked and not multiple

	}

}
