#pragma once

#include <vector>
#include "CoreScene.h"
#include "Panel.h"

namespace DreamEngine {

	struct PanelSceneDef : public Core::SceneDef {

	};

	class PanelScene : public Core::Scene {
	public:
		PanelScene(PanelSceneDef def);

		void addPanel(Panel * panel);

		// Inherited via Scene
		virtual void update(float delta) override;
		virtual void draw(float delta) override;
		virtual void destroy() override;
		virtual void load(float * progress) override;
		virtual void start() override;
		virtual void end() override;
		virtual void save(Core::DataManager * dataManager) override;
	private:
		std::vector<Panel*> panels;
	};

};