#include "Window.h"

DreamEngine::Window::Window(WindowDef def)
	:size(def.size), title(def.title), style(def.style), contextSettings(def.contextSettings)
{
	window = new sf::RenderWindow(sf::VideoMode(size.x, size.y), title, style, contextSettings);
}

DreamEngine::Window::~Window()
{
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

void DreamEngine::Window::events()
{
	sf::Event events;
	while (window->pollEvent(events)) {
		switch (events.type)
		{
			/*case sf::Event::KeyPressed:
			std::cout << events.key.code << std::endl;
			break;*/
		case sf::Event::Closed:
			close();
			break;
		default:
			break;
		}
	}


}
