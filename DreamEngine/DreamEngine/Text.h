#pragma once

#include "Font.h"
#include "CoreDrawable.h"
#include "Engine.h"
#include "CoreWindow.h"

namespace DreamEngine {

	struct TextDef : public Core::DrawableDef {
		sf::Vector2f position = { 0, 0 };
		std::string txt = "Text Drawable";
		Font * font = nullptr;
		int fontSize = 30;
		sf::Color color = sf::Color::Black;
		Core::Window * window;
	};

	class Text : public Core::Drawable
	{
	public:
		Text(TextDef textDefinition);
		~Text();

		void setFont(Font font);
		void setText(std::string text);
		void setPosition(sf::Vector2f position);
		void setWorldPosition(b2Vec2 position);
		void setColor(sf::Color color);
		void setSize(int fontSize);
		// Inherited via Drawable
		virtual void draw() override;

		// Inherited via Drawable
		virtual void onDestroy() override;
		virtual void load() override;
		virtual ObjectData save() override;

		sf::Text * getText();
	private:
		TextDef textDefinition;
		sf::Text * text = new sf::Text;
		Core::Window * window;



	};

};