#include "CameraManager.h"

DreamEngine::CameraManager::CameraManager()
{
}


DreamEngine::CameraManager::~CameraManager()
{
	for (Camera * c = (Camera*)getFirst(); c != nullptr; c = (Camera*)getNext()) {
		delete c;
	}
}

DreamEngine::Camera * DreamEngine::CameraManager::get(Cameras camera)
{
	return (Camera*)ObjectManager::get(int(camera));
}

void DreamEngine::CameraManager::draw(sf::RenderWindow * window)
{
	for (Camera * c = (Camera*)getFirst(); c != nullptr; c = (Camera*)getNext()) {
		window->setView(c->getView());
		c->display();
	}
}