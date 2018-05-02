#pragma once

#include "Builder.h"
#include "PanelScene.h"

#include "Panel.h"
#include "UICheckbox.h"
#include "UIButton.h"
#include "UITextInput.h"
#include "Window.h"

#define FONTSIZE 20

namespace DreamEngine {

	class EditorPanelBuilder {
	public:
		EditorPanelBuilder(Builder * builder, PanelScene * panelScene, Window * window);
		void createPanelsFromBuilders();
	private:
		std::vector<Core::ObjectBuilder*> builders;
		PanelScene * panelScene;
		Window * window;

		void createPanel(Core::ObjectBuilder* builder);

		void createUIElement(UserInterface::Panel * panel, Trio<std::string, std::string, ObjectDataType> data);
	};

};