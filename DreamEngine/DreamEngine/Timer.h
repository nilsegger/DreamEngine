#pragma once
#include "SFML\Graphics.hpp"

namespace DreamEngine {

	class Timer
	{
	public:
		virtual void start();
		virtual void restart();
		virtual float getElapsedTime();
	private:
		sf::Clock clock;
	};

};