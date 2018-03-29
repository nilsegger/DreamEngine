#pragma once

#include "CoreScene.h"
#include <Box2D\Box2D.h>
#include "CollisionListener.h"
#include "WorldObjectManager.h"
#include "DrawableManager.h"

#include "Sprite.h"

namespace DreamEngine {

	struct DefaultSceneDef : public Core::SceneDef {
		CollisionListener * collisionListener = nullptr;
		b2World * world = nullptr;
		b2Vec2 gravity = {0,0};
		WorldObjectManager * actors = nullptr;
		WorldObjectManager * shapes = nullptr;
		DrawableManager * drawables = nullptr;
	};

	class DefaultScene : public Core::Scene {
	public:
		DefaultScene(DefaultSceneDef def);

		// Inherited via Scene
		virtual void update(float delta) override;
		virtual void draw(float delta) override;
		virtual void destroy() override;
		virtual void load(float * progress) override;
		virtual void start() override;
		virtual void end() override;
		virtual void save(Core::DataManager * dataManager) override;



		CollisionListener * collisionListener = nullptr;
		b2World * world = nullptr;
		WorldObjectManager * actors = nullptr;
		WorldObjectManager * shapes = nullptr;
		DrawableManager * drawables = nullptr;

	};

}