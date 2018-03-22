#pragma once

#include <SFML\Graphics.hpp>
#include "Camera.h"

namespace DreamEngine {

	class Mouse
	{
	public:
		Mouse(sf::RenderWindow * window);
		~Mouse();

		sf::RenderWindow * window;
		sf::Vector2f getMouseScreenPosition(); //Absolute mouse position
		sf::Vector2f getMouseScreenPosition(DreamEngine::Camera * camera); //Relative mouse position to camera
		b2Vec2 getMouseWorldPosition(DreamEngine::Camera * camera);
	};

}