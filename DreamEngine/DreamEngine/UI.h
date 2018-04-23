#pragma once

#include "Window.h"
#include "Launchable.h"
#include "SceneManager.h"
#include "Builder.h"
#include "Panel.h"
#include "PanelScene.h"

namespace DreamEngine {

	class UILauncher : public Launchable {
	public:


		// Inherited via Launchable
		virtual void init() override;

		virtual void end() override;

		virtual bool update() override;
	private:
		DreamEngine::Window * window = nullptr;
		DreamEngine::CameraManager * cameraManager = nullptr;
		DreamEngine::Camera * camera = nullptr;
		DreamEngine::SceneManager * sceneManager = nullptr;
		DreamEngine::Builder * builder = nullptr;
		DreamEngine::DataManager * dataManager = nullptr;
		DreamEngine::PanelScene * panelScene = nullptr;
	};

};