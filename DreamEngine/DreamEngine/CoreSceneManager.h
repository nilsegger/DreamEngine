#pragma once

#include "ObjectManager.h"
#include "CoreScene.h"

namespace DreamEngine::Core {

	class SceneManager : public ObjectManager {
	public:
		virtual void start() = 0;
		virtual void startScene(Core::Scene * scene) = 0;
		virtual void startScene(int id) = 0;
		virtual void loadScene(Core::Scene * scene) = 0;
		virtual void loadScene(int id) = 0;
		virtual void endScene(Core::Scene * scene) = 0;
		virtual void endScene(int id) = 0;
		virtual void baseUpdate() = 0;
		virtual void update(float delta) = 0;
		virtual void draw(float delta) = 0;
		virtual void save() = 0;
		virtual void destroy() = 0;

	};
};