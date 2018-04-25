#pragma once

#include <vector>
#include "CoreScene.h"
#include "Panel.h"
#include "CameraManager.h"

namespace DreamEngine {

	struct PanelSceneDef : public Core::SceneDef {
		CameraManager * cameraManager = nullptr;
	};

	class PanelScene : public Core::Scene {
	public:
		PanelScene(PanelSceneDef def);

		void addPanel(UserInterface::Panel * panel);

		// Inherited via Scene
		virtual void update(float delta) override;
		virtual void draw(float delta) override;
		virtual void destroy() override;
		virtual void load(float * progress) override;
		virtual void start() override;
		virtual void end() override;
		virtual void save(Core::DataManager * dataManager) override;
	private:
		std::vector<UserInterface::Panel*> panels;
		CameraManager * cameraManager;
	};

};