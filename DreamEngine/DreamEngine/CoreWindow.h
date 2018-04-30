#pragma once

#include <SFML\Graphics.hpp>
#include "CoreDrawable.h"
#include "Timer.h"

namespace DreamEngine::Core {

	class Window {
	public:
		virtual bool isOpen() const = 0;
		virtual void clear() = 0;
		virtual void display() = 0;
		virtual void draw(DreamEngine::Core::Drawable * drawable) = 0;
		virtual void close() = 0;
		virtual void show(bool flag = true) = 0;
		virtual sf::RenderWindow * getWindow() = 0;

		virtual std::string getTextEnteredUpdateCycle() = 0;
		virtual std::string getTextEnteredDrawCycle() = 0;

		virtual void updateDone() = 0;
		virtual int getKeys() = 0;
		Timer frameTimer;
	};


}