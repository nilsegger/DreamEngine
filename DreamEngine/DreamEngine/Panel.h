#pragma once

#include "Window.h"
#include "ObjectData.h"
#include "Drawable.h"
#include "Mouse.h"

#include "UIColors.h"
#include "UIElement.h"

#define topbarsize	20

namespace DreamEngine::UserInterface {

	struct PanelDef : DrawableDef {
		sf::Vector2f position = {0.f,0.f};
		sf::Vector2f fontSize = { 100.f,100.f };
	};

	class Panel : public Drawable {
	public:
		Panel(PanelDef def);
		~Panel();
		// Inherited via Drawable
		virtual void draw() override;

		virtual void onDestroy() override;

		virtual void load() override;

		virtual ObjectData save() override;

		void dragEvent();
		void closeEvent();

		bool isFocused();

		void addUIElement(UIElement * element, sf::Vector2f offset);

	private:
		sf::Vector2f fontSize;
		sf::Vector2f position;

		sf::RectangleShape * topbar = nullptr;
		sf::RectangleShape * body = nullptr;
		sf::RectangleShape * close = nullptr;



		Mouse mouse;
		
		sf::Vector2f dragOffset = {0.f,0.f};
		bool beingDragged = false;

		static bool panelIsBeingDragged; 
		static int lastFocused;

		bool closed = false;
		bool closable = true;

		bool dragable = true;
		// blocking other panels, so that only one is dragged per mouse click

		std::vector<UIElement*> elements;
		void setElementsPositions();

		void onElementsClickEvent();
	};

};