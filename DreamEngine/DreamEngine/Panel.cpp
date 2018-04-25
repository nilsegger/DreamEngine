#include "Panel.h"

bool DreamEngine::UserInterface::Panel::panelIsBeingDragged = false;
int DreamEngine::UserInterface::Panel::lastFocused = -1;

DreamEngine::UserInterface::Panel::Panel(PanelDef def)
	:Drawable(def), fontSize(def.fontSize), position(def.position), mouse(window->getWindow())
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

	if(isFocused()) body->setFillColor(CLR_PANEL_FOCUSED_BG);
	else body->setFillColor(CLR_PANEL_UNFOCUSED_BG);

	close->setPosition(position + sf::Vector2f{fontSize.x - topbarsize, 0.f});
	topbar->setPosition(position);
	body->setPosition(position + sf::Vector2f{ 0,topbarsize }); //offset for bar

	window->getWindow()->draw(*body);
	window->getWindow()->draw(*topbar);
	window->getWindow()->draw(*close);

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
	topbar = new sf::RectangleShape;
	topbar->setSize(sf::Vector2f{ fontSize.x, topbarsize });
	topbar->setFillColor(CLR_PANEL_TOPBAR);

	close = new sf::RectangleShape;
	close->setSize(sf::Vector2f{ topbarsize, topbarsize });
	close->setFillColor(CLR_PANEL_CLOSABLE);

	if (closable == false) {
		close->setFillColor(CLR_PANEL_UNCLOSABLE);
	}

	body = new sf::RectangleShape;
	body->setSize(fontSize);
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

		if (mousePos.x >= position.x && mousePos.x <= position.x + fontSize.x - topbarsize &&
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

	if (mousePos.x >= position.x + fontSize.x - topbarsize && mousePos.x <= position.x + fontSize.x &&
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

		if (mousePos.x >= elements[i]->getPosition().x && mousePos.x <= elements[i]->getPosition().x + elements[i]->getBounds().x
			&&mousePos.y >= elements[i]->getPosition().y && mousePos.y <= elements[i]->getPosition().y + elements[i]->getBounds().y) {

			if (elements[i]->hovering == false) {
				elements[i]->hovering = true;
				elements[i]->onHover();
			}

		}
		else {
			if (elements[i]->hovering) {
				elements[i]->hovering = false;
				elements[i]->onHoverEnd();
			}
		}

		//onClick and stuff

	}

}
