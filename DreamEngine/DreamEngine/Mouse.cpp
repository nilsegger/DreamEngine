#include "Mouse.h"



DreamEngine::Mouse::Mouse(sf::RenderWindow * window)
	:window(window)
{
}


DreamEngine::Mouse::~Mouse()
{
}

sf::Vector2f DreamEngine::Mouse::getMouseScreenPosition()
{
	
	
	if (window == nullptr) return{ -1,-1 };
	return sf::Vector2f(sf::Mouse::getPosition(*window));

	
}

sf::Vector2f DreamEngine::Mouse::getMouseScreenPosition(DreamEngine::Camera * camera)
{
	
	/*float scaleX = float(window->getSize().x) / camera->getView().getSize().x;
	float scaleY = float(window->getSize().y) / camera->getView().getSize().y;

	sf::Vector2f positionScaled = sf::Vector2f{ getMouseScreenPosition().x / scaleX, getMouseScreenPosition().y / scaleY };//  - camera->getScreenPosition();*/
	

	//sf::Vector2f offset = { float(window->getSize().x) * camera->getView().getViewport().left , float(window->getSize().y) *  camera->getView().getViewport().top };


	//sf::Vector2f positionViewportScaled = { positionScaled.x / camera->getView().getViewport().width - float(window->getSize().x) *  camera->getView().getViewport().left, positionScaled.y / camera->getView().getViewport().height - float(window->getSize().y) *  camera->getView().getViewport().top };
	
	sf::Vector2f offset = { float(window->getSize().x) *  camera->getView().getViewport().left,  float(window->getSize().y) *  camera->getView().getViewport().top };

	//if(camera->id == 2) std::cout << float(window->getSize().x) *  camera->getView().getViewport().left << std::endl;

	return getMouseScreenPosition() - offset;//- offset;//positionViewportScaled;// -offset;

}

b2Vec2 DreamEngine::Mouse::getMouseWorldPosition(DreamEngine::Camera * camera)
{
	return Engine::pixelToWorld(getMouseScreenPosition(camera));
}

bool DreamEngine::Mouse::leftIsClicked()
{
	return sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

bool DreamEngine::Mouse::rightIsClicked()
{
	return sf::Mouse::isButtonPressed(sf::Mouse::Right);
}
