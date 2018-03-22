#include "Camera.h"



DreamEngine::Camera::Camera(CameraDefinition cameraDefinition)
	:windowSize(cameraDefinition.windowSize), count(0), window(cameraDefinition.window)
{
	view.reset(sf::FloatRect(0.f, 0.f, float(cameraDefinition.windowSize.x), float(cameraDefinition.windowSize.y)));
}


DreamEngine::Camera::~Camera()
{
}

void DreamEngine::Camera::move(sf::Vector2f offset)
{
	setCameraScreenPosition(getScreenPosition() + offset);
}

void DreamEngine::Camera::setCameraScreenPosition(sf::Vector2f position)
{
	this->position = position;
	view.setCenter({float(windowSize.x / 2.f) - position.x, float(windowSize.y/2.f) - position.y });
}

void DreamEngine::Camera::setCameraWorldPosition(b2Vec2 position)
{
	setCameraScreenPosition(Engine::worldToPixel(-position));
}

void DreamEngine::Camera::setViewport(float ratioX, float ratioY, float widthRatio, float heightRatio)
{
	view.setViewport(sf::FloatRect(ratioX,ratioY, widthRatio, heightRatio));
}

void DreamEngine::Camera::rotate(float degrees)
{
	view.rotate(degrees);
}

void DreamEngine::Camera::setRotation(float degrees)
{
	view.setRotation(degrees);
}

b2Vec2 DreamEngine::Camera::getWindowWorldSize()
{
	return Engine::pixelToWorld(windowSize);
}

sf::View DreamEngine::Camera::getView() const
{
	return view;
}

sf::Vector2f DreamEngine::Camera::getScreenPosition() const
{
	return position;
}

void DreamEngine::Camera::draw(DreamEngine::Core::Drawable * drawable)
{
	if (count >= MAX_DRAWABLES) {
		std::cout << "Max drawables exceeded." << std::endl;
	}
	drawables[count] = drawable;
	count++;
}

void DreamEngine::Camera::display()
{

	for (int i = 0; i < count; i++) {
		drawables[i]->draw();
	}
	count = 0;

	
}
