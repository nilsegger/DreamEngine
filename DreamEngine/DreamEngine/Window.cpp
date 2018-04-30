#include "Window.h"

DreamEngine::Window::Window(WindowDef def)
	:fontSize(def.fontSize), title(def.title), style(def.style), contextSettings(def.contextSettings)
{
	window = new sf::RenderWindow(sf::VideoMode(fontSize.x, fontSize.y), title, style, contextSettings);
}

DreamEngine::Window::~Window()
{
	if(window != nullptr) delete window;
	window = nullptr;
}

bool DreamEngine::Window::isOpen() const
{
	if (window == nullptr) return false;
	return window->isOpen();
}

void DreamEngine::Window::clear()
{
	if (window == nullptr) return;
	events();
	window->clear(sf::Color::Black);
}

void DreamEngine::Window::display()
{
	if (window == nullptr) return;
	/*if (cameraManager == nullptr) {
	std::cout << "No cameras selected" << std::endl;
	Engine::waitForKeyPress();
	exit(-1);
	}*/

	if (cameraManager != nullptr) cameraManager->draw(window);
	window->display();
	frameTimer.restart();

	textEnteredDraw = "";
	pressedKeysDuringDrawCycleSize = 0;
}

void DreamEngine::Window::draw(DreamEngine::Core::Drawable * drawable)
{
	if (window == nullptr) return;
	drawable->draw();
}

void DreamEngine::Window::close()
{
	window->close();
}

void DreamEngine::Window::show(bool flag)
{
	window->setVisible(flag);
}

sf::RenderWindow * DreamEngine::Window::getWindow()
{
	return window;
}

void DreamEngine::Window::setCameraManager(CameraManager * cameraManager)
{
	this->cameraManager = cameraManager;
}

int DreamEngine::Window::getKeys()
{
	if (getKeysCurrent < pressedKeysDuringDrawCycleSize) {
		getKeysCurrent++;
		return pressedKeysDuringDrawCycle[getKeysCurrent - 1];
	}
	getKeysCurrent = 0;
	return 0;
}

void DreamEngine::Window::events()
{
	sf::Event events;
	while (window->pollEvent(events)) {
		switch (events.type)
		{
			case sf::Event::KeyPressed:
			//std::cout << events.key.code << std::endl;
			pressedKeysDuringDrawCycle[pressedKeysDuringDrawCycleSize] = events.key.code;
			pressedKeysDuringDrawCycleSize++;
			break;
		case sf::Event::Closed:
			close();
			break;
		case sf::Event::TextEntered:
			if (events.text.unicode < 128) {
				textEnteredUpdate += static_cast<char>(events.text.unicode);
				textEnteredDraw += static_cast<char>(events.text.unicode);
			}
			break;
		default:
			break;
		}
	}

}

std::string DreamEngine::Window::getTextEnteredUpdateCycle()
{
	return textEnteredUpdate;
}

std::string DreamEngine::Window::getTextEnteredDrawCycle()
{
	return textEnteredDraw;
}

void DreamEngine::Window::updateDone()
{
	textEnteredUpdate = "";
}
