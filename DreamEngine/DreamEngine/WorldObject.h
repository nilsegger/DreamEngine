#pragma once

#include "CoreObject.h"
#include "ObjectData.h"
#include <Box2D\Box2D.h>

namespace DreamEngine::Core {

	struct WorldObjectDef : public ObjectDef {

	};

	class WorldObject : public Object {
	public:
		WorldObject(WorldObjectDef worldObjectDef);

		bool destroyObject = false;
		bool isColliding = false;
		
		virtual void instantiate(DreamEngine::ObjectData data) = 0;
		virtual void destroy();
		virtual void onDestroy() = 0;
		virtual void draw(float delta) = 0;
		virtual void update(float delta) = 0;
		virtual DreamEngine::ObjectData save() = 0;

		void beginCollision();
		void endCollision();
		virtual void beginActorCollision(void * other, b2Contact * contact) = 0;
		virtual void endActorCollision(void * other, b2Contact * contact) = 0;
		virtual void beginShapeCollision(void * other, b2Contact * contact) = 0;
		virtual void endShapeCollision(void * other, b2Contact * contact) = 0;
	private:
		unsigned int collisionCount = 0;
	};

};

