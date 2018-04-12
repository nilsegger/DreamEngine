#pragma once

#include "CoreDrawable.h"
#include <SFML\Graphics.hpp>

namespace DreamEngine::Core {

	struct ButtonDef : public DrawableDef {
		sf::Rect<float> rect;
	};

	class Button : public Drawable {
	public:
		Button(ButtonDef def);
		virtual void onClick() = 0;
		virtual void onEndClick() = 0;
		virtual void onMouseOn() = 0;
		virtual void onMouseLeave() = 0;
		virtual bool onButton(sf::Vector2f point);
		bool isActive;
	private:
		sf::Rect<float> rect;
	};

};