#pragma once

#include <SFML\Graphics.hpp>
#include <Box2D\Box2D.h>
#include <iostream>

namespace DreamEngine {

	class Engine
	{
	public:
		static constexpr float SCALE = 100.f;
		static constexpr int MAX_VERTICES = 10;

		static float worldToPixel(float val);
		static sf::Vector2f worldToPixel(b2Vec2 val);
		static sf::Vector2i worldToPixeli(b2Vec2 val);
		static b2Vec2 pixelToWorld(sf::Vector2i val);
		static b2Vec2 pixelToWorld(sf::Vector2f val);
		static b2Vec2 pixelToWorld(sf::Vector2u val);
		static void waitForKeyPress(std::string message = "");
		static bool intToBool(int val);
		static b2Vec2 angleToForward(float angle);
		static float radianToDeg(float angle);
		static float degToRadian(float degree);
	};

}