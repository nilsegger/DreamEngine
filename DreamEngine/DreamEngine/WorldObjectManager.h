#pragma once

#include "ObjectManager.h"
#include "WorldObject.h"

namespace DreamEngine {

	class WorldObjectManager : public ObjectManager {

	public:
		void draw(float delta);
		virtual void update(float delta);
		virtual bool destroyObject(DreamEngine::Core::WorldObject * o);
		virtual void destroyObjects();
	};

};