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

	setElementsPositions();

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

	setElementsPositions();
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

/*void DreamEngine::UserInterface::Panel::addUIElement(UIElement * element, sf::Vector2f offset)
{
	elements.push_back(element);
	element->setPosition(position + offset + sf::Vector2f{0, topbarsize});
	element->offset = offset;
}*/

void DreamEngine::UserInterface::Panel::addUIElement(UIElement * element, int row, int cell)
{
	for (int i = int(rows.size()) - 1; i <= row; i++) rows.push_back(std::vector<UIElement*>());
	for (int i = int(rows[row].size()) - 1; i <= cell; i++) rows[row].push_back(nullptr);

	rows[row][cell] = element;
	elements.push_back(element);
	
}

/*void DreamEngine::UserInterface::Panel::setElementsPositions()
{
	for (int i = 0; i < int(elements.size()); i++) {
		elements[i]->setPosition(position + elements[i]->offset + sf::Vector2f{ 0, topbarsize });
	}
}*/

void DreamEngine::UserInterface::Panel::onElementsClickEvent()
{
	if (isFocused() == false) return;

	bool elementClicked = false;

	for (int i = 0; i < int(elements.size()); i++) {
		
		sf::Vector2f mousePos = mouse.getMouseScreenPosition();
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
					elementClicked = true;

					if (focusedElement != elements[i]) {
						elements[i]->onFocus();
						focusedElement = elements[i];
						blockUnFocus = true;
					}
				}
			}
			else {
				if (elements[i]->clicked) {
					elements[i]->clicked = false;
					elements[i]->onClickEnd();
					elementClicked = true;
				}
			}

		}
		else {
			if (elements[i]->hovering) {
				elements[i]->hovering = false;
				elements[i]->onHoverEnd();
			}
			//break; // only want one element clicked and not multiple
		}

	
	}
	if (elementClicked == false && mouse.leftIsClicked() == true && blockUnFocus == false) {
		if (focusedElement != nullptr) {
			focusedElement->onFocusLost();
		}
		focusedElement = nullptr;
	}
	if (mouse.leftIsClicked() == false) blockUnFocus = false;

}

void DreamEngine::UserInterface::Panel::setElementsPositions()
{
	sf::Vector2f offset = {ELEMENTSPADDING,ELEMENTSPADDING};

	for (int r = 0; r < int(rows.size()); r++) {

		float rowHeight = 0.f;

		for (int e = 0; e < int(rows[r].size()); e++) {
			if (rows[r][e] == nullptr) continue;
			if (rows[r][e]->getBounds().y > rowHeight) rowHeight = rows[r][e]->getBounds().y;
		}

		for (int e = 0; e < int(rows[r].size()); e++) {
			if (rows[r][e] == nullptr) continue;
			
			float localOffsetY = (rowHeight - rows[r][e]->getBounds().y) / 2.f;
			rows[r][e]->setPosition(position + sf::Vector2f{ offset.x, offset.y + localOffsetY } +sf::Vector2f{0,topbarsize});

			offset.x += ELEMENTSPADDING + rows[r][e]->getBounds().x;

			if (offset.x > rowsSize.x) rowsSize.x = offset.x;
		}

		offset.y += rowHeight + ELEMENTSPADDING;
		if (offset.y > rowsSize.y) rowsSize.y = offset.y;

		offset.x = ELEMENTSPADDING;
	}

	size.x = rowsSize.x;
	topbar->setSize(sf::Vector2f{ rowsSize.x , topbar->getSize().y });
	body->setSize(rowsSize);

	rowsSize = { 0.f,0.f };
}
