#pragma once

#include "ObjectManager.h"
#include "CoreScene.h"

namespace DreamEngine::Core {

	class SceneManager : public ObjectManager {

		virtual void start() = 0;
		virtual void startScene(Scene * scene) = 0;
		virtual void startScene(int id) = 0;
		virtual void loadScene(Scene * scene) = 0;
		virtual void loadScene(int id) = 0;
		virtual void endScene(Scene * scene) = 0;
		virtual void endScene(int id) = 0;
		virtual void baseUpdate() = 0;
		virtual void update(float delta) = 0;
		virtual void draw(float delta) = 0;
		virtual void save() = 0;
		virtual void destroy() = 0;

	};
};