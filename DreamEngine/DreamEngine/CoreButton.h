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
		virtual void onclick() = 0;
		virtual void onMouseOn() = 0;
		virtual void onMouseLeave() = 0;
		sf::Rect<float> rect;
	};

};