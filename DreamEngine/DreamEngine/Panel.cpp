#include "Panel.h"

bool DreamEngine::Panel::panelIsBeingDragged = false;
int DreamEngine::Panel::lastFocused = -1;

DreamEngine::Panel::Panel(PanelDef def)
	:Drawable(def), size(def.size), position(def.position), mouse(window->getWindow()), cameraManager(def.cameraManager)
{
}

void DreamEngine::Panel::draw()
{
	closeEvent();
	dragEvent();
	close->setPosition(position + sf::Vector2f{size.x - topbarsize, 0.f});
	topbar->setPosition(position);
	body->setPosition(position + sf::Vector2f{ 0,topbarsize }); //offset for bar
	
	if (lastFocused == id) {
		cameraManager->get() //when focused draw on focused camera, cameramanger get cam by string name
	}

	window->getWindow()->draw(*body);
	window->getWindow()->draw(*topbar);
	window->getWindow()->draw(*close);
}

void DreamEngine::Panel::onDestroy()
{
	delete body;
	delete topbar;
	delete close;
	close = nullptr;
	body = nullptr;
	topbar = nullptr;
}

void DreamEngine::Panel::load()
{
	topbar = new sf::RectangleShape;
	topbar->setSize(sf::Vector2f{ size.x, topbarsize });
	topbar->setFillColor(sf::Color::Color(77, 82, 89));

	close = new sf::RectangleShape;
	close->setSize(sf::Vector2f{ topbarsize, topbarsize });
	close->setFillColor(sf::Color::Color(191, 48, 74));

	if (closable == false) {
		close->setFillColor(sf::Color::Color(191, 48, 74, 75));
	}

	body = new sf::RectangleShape;
	body->setSize(size);
	body->setFillColor(sf::Color::Color(77,82,89,127));
}

DreamEngine::ObjectData DreamEngine::Panel::save()
{
	return ObjectData();
}

void DreamEngine::Panel::dragEvent()
{
	if (beingDragged == true) {
		if (mouse.leftIsClicked() == false) {
			beingDragged = false;
			panelIsBeingDragged = false;
			return;
		}
		position = mouse.getMouseScreenPosition() - dragOffset;
	}
	else {
		if (panelIsBeingDragged) return;

		if (mouse.leftIsClicked() == false) return;

		sf::Vector2f mousePos = mouse.getMouseScreenPosition();

		if (mousePos.x >= position.x && mousePos.x <= position.x + size.x - topbarsize &&
			mousePos.y >= position.y && mousePos.y <= position.y + topbarsize) {

			dragOffset = mousePos - position;

			beingDragged = true;
			panelIsBeingDragged = true;
		}


	}
}

void DreamEngine::Panel::closeEvent()
{

	if (panelIsBeingDragged || beingDragged || closed || closable == false) return;

	if (mouse.leftIsClicked() == false) return;

	sf::Vector2f mousePos = mouse.getMouseScreenPosition();

	if (mousePos.x >= position.x + size.x - topbarsize && mousePos.x <= position.x + size.x &&
		mousePos.y >= position.y && mousePos.y <= position.y + topbarsize) {
		closed = true;
		std::cout << "Closing panels is not supported yet..." << std::endl;
	}


	
}

