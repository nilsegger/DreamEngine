#pragma once

#include "Window.h"
#include "ObjectData.h"
#include "Drawable.h"
#include "Mouse.h"

#include "UIColors.h"
#include "UIElement.h"

#include "Text.h"

#define topbarsize	20
#define ELEMENTSPADDING 10.f

namespace DreamEngine::UserInterface {

	struct PanelDef : DrawableDef {
		sf::Vector2f position = {0.f,0.f};
		sf::Vector2f size = { 100.f,100.f };
		std::string panelTitle = "Panel";
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

		void addUIElement(UIElement * element, int row = 0, int cell = 0);

	private:
		sf::Vector2f size;
		sf::Vector2f position;

		sf::RectangleShape * topbar = nullptr;
		sf::RectangleShape * body = nullptr;
		sf::RectangleShape * close = nullptr;


		std::string title;
		Font * font = nullptr;
		Text * text = nullptr;

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
		UIElement * focusedElement = nullptr;
		bool blockUnFocus = false;
		std::vector<std::vector<UIElement*>> rows;
		sf::Vector2f rowsSize = {0.f,0.f};
		void setElementsPositions();

		void onElementsClickEvent();

	};

};