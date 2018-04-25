#pragma once

#include "Drawable.h"

namespace DreamEngine::UserInterface {

	struct UIElementDef : public DrawableDef {

	};

	class UIElement : public Drawable {
	public:
		UIElement(UIElementDef def);
		virtual sf::Vector2f getBounds() = 0;
		virtual void setPosition(sf::Vector2f absolutePos) = 0;
		sf::Vector2f offset = { 0,0 };
	};

};