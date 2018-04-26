#pragma once

#include "Window.h"
#include "Launchable.h"
#include "SceneManager.h"
#include "Builder.h"
#include "Panel.h"
#include "PanelScene.h"
#include "UICheckbox.h"
#include "UIButton.h"
namespace DreamEngine {

	class UILauncher : public Launchable {
	public:


		// Inherited via Launchable
		virtual void init() override;

		virtual void end() override;

		virtual bool update() override;

		static void test(DreamEngine::UserInterface::UIElement * element);
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