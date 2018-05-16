#pragma once

#include "Drawable.h"
#include <string>
#include "Font.h"
#include "Text.h"

#include "UIColors.h"
#include "UIElement.h"

#define bottomBorderHeight 1.f

namespace DreamEngine::UserInterface {

	struct ButtonDef : public UIElementDef {
		void (*onClickFunc)(DreamEngine::UserInterface::UIElement*) = nullptr;
		int fontSize = 23;
		std::string text = "DefaultButton";
		bool clickable = true; //Not implemented
	};

	class Button : public UIElement {
	public:
		Button(ButtonDef def);

		// Inherited via Drawable
		virtual void draw() override;

		virtual void onDestroy() override;

		virtual void load() override;

		virtual DreamEngine::ObjectData save() override;

		// Inherited via UIElement
		virtual sf::Vector2f getBounds() override;

		virtual void setPosition(sf::Vector2f absolutePos) override;

		// Inherited via UIElement
		virtual sf::Vector2f getPosition() override;

		virtual void onClickBegin() override;

		virtual void onClickEnd() override;

		virtual void onHover() override;

		virtual void onHoverEnd() override;
		
	private:
		//void onClickEvent();

		float padding = 5.f;
		int fontSize = 23;
		sf::Vector2f size; //has to be calculated by string size and font size
		//sf::Vector2f position = {0,0};
		std::string buttonText;

		Font * font = nullptr;
		Text * text = nullptr;
		sf::RectangleShape * background = nullptr;
		sf::RectangleShape * bottomBorder = nullptr;

		sf::Vector2f position = { 0,0 };

		void (*onClickFunc)(DreamEngine::UserInterface::UIElement*);

		// Inherited via UIElement
		virtual void onFocus() override;
		virtual void onFocusLost() override;
	};

}

