#pragma once
#include "CoreSceneManager.h"
#include <thread>
#include "ObjectManager.h"
#include "CoreScene.h"
#include "CoreWindow.h"
#include "Timer.h"
#include "DataManager.h"
#include "Text.h"
#include "CoreBuilder.h"

#include <assert.h>

#define MAX_ACTIVE_SCENES 100

namespace DreamEngine {

	struct SceneManagerDef {
		Core::Window * window;
		Core::Builder * builder;
		DataManager * dataManager;
	};

	class SceneManager : public Core::SceneManager {

	public:
		SceneManager(SceneManagerDef def);

		// Inherited via SceneManager
		virtual void start() override;

		virtual void startScene(Core::Scene * scene) override;

		virtual void startScene(int id) override;

		virtual void loadScene(Core::Scene * scene) override;

		virtual void loadScene(int id) override;

		virtual void endScene(Core::Scene * scene) override;

		virtual void endScene(int id) override;

		virtual void baseUpdate() override;

		virtual void update(float delta) override;

		virtual void draw(float delta) override;

		virtual void save() override;

		virtual void destroy() override;
	private:

		Core::Scene * activeScenes[MAX_ACTIVE_SCENES];
		int activeSceneCount = 0;

		Core::Window * window;
		
		Core::Builder * builder;

		DataManager * dataManager;

		Timer loopTimer;

		void updateScene();
		void drawWindow();

	};


};
