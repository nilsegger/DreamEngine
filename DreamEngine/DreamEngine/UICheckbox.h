#pragma once

#include "UIElement.h"
#include "Text.h"


namespace DreamEngine::UserInterface {

	struct CheckboxDef : UIElementDef {
		sf::Vector2f size = {25.f,25.f};
		std::string labelText = "Checkbox Label";
		float labelOffset = 5.f;
		bool checked = false;
	};

	class Checkbox : public UIElement {
	public:
		Checkbox(CheckboxDef def);

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

		bool isChecked();
	private:
		sf::Vector2f position;
		sf::Vector2f size;
		sf::RectangleShape * box = nullptr;

		std::string labelText;
		float labelOffset = 5.f;

		Font * font = nullptr;
		Text * text = nullptr;

		bool checked;

		// Inherited via UIElement
		virtual void onFocus() override;
		virtual void onFocusLost() override;
	};

};