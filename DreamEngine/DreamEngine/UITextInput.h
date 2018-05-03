#pragma once

#include "UIElement.h"
#include "Text.h"
#include "ObjectData.h"

namespace DreamEngine::UserInterface{

	struct TextInputDef : public UIElementDef {
		int fontSize = 23;
		float maxWidth = 100.f;
		float textPadding = 5.f;
		ObjectDataType type = NONE;
	};

	class TextInput : public UIElement {
	public:
		TextInput(TextInputDef def);
		
		// Inherited via UIElement
		virtual void draw() override;
		virtual void onDestroy() override;
		virtual void load() override;
		virtual DreamEngine::ObjectData save() override;
		virtual sf::Vector2f getBounds() override;
		virtual sf::Vector2f getPosition() override;
		virtual void setPosition(sf::Vector2f absolutePos) override;
		virtual void onClickBegin() override;
		virtual void onClickEnd() override;
		virtual void onHover() override;
		virtual void onHoverEnd() override;

		void setLabel(std::string txt);
		void setText(std::string txt);
		std::string getString();
		int getInt();
		float getFloat();

		ObjectDataType getType();
	private:
		sf::Vector2f position;
		sf::Vector2f size;
		sf::RectangleShape * background;
		sf::RectangleShape * cursorAt;
		Font * font;
		Text * text;
		Text * label;
		int fontSize;
		float maxWidth;
		float textPadding;
		sf::Vector2f offsetLabelBox = {10.f,0.f};
		bool empty = true;

		std::string labelText = "";
		std::string enteredText = "";
		float cursorPosition = 0.f;
		void addText(std::string txt);

		bool deletePressed = false;
		bool focused = false;

		// Inherited via UIElement
		virtual void onFocus() override;
		virtual void onFocusLost() override;

		ObjectDataType type;
	};

};
