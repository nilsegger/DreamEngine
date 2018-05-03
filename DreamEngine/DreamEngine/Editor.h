#pragma once

#include "DreamEngine.h"
#include "Launchable.h"

#include "PanelScene.h"

#include "PolygonDrawableBuilder.h"
#include "PolygonShapeBuilder.h"

#include "Panel.h"
#include "PanelScene.h"
#include "UICheckbox.h"
#include "UIButton.h"
#include "UITextInput.h"

#include "EditorPanelBuilder.h"

namespace DreamEngine {


	class Editor : public Launchable {
	public:
		// Inherited via Launchable
		virtual void init() override;
		virtual void end() override;
		virtual bool update() override;
	private:
		DreamEngine::Window * window = nullptr;

		DreamEngine::CameraManager * cameraManager = nullptr;

		DreamEngine::SceneManager * sceneManager = nullptr;
		
		DreamEngine::PanelScene * panelScene = nullptr;

		DreamEngine::Builder * builder = nullptr;
		DreamEngine::DataManager * dataManager = nullptr;
		DreamEngine::DefaultScene * defaultScene = nullptr;

		void initGame();
		void initUI();
	};


};