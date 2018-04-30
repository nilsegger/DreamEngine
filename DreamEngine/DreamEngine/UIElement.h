#pragma once

#include "Drawable.h"

namespace DreamEngine::UserInterface {

	struct UIElementDef : public DrawableDef {

	};

	class UIElement : public Drawable {
	public:
		UIElement(UIElementDef def);
		virtual sf::Vector2f getBounds() = 0;
		virtual sf::Vector2f getPosition() = 0;
		virtual void setPosition(sf::Vector2f absolutePos) = 0;
		sf::Vector2f offset = { 0,0 };

		virtual void onClickBegin() = 0;
		virtual void onClickEnd() = 0;
		virtual void onHover() = 0;
		virtual void onHoverEnd() = 0;

		virtual void onFocus() = 0;
		virtual void onFocusLost() = 0;

		bool clicked = false;
		bool hovering = false;
	};

};