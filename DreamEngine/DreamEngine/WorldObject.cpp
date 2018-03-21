#include "WorldObject.h"

DreamEngine::Core::WorldObject::WorldObject(WorldObjectDef worldObjectDef)
	:Object(worldObjectDef)
{
}

void DreamEngine::Core::WorldObject::destroy()
{
	destroyObject = true;
}

void DreamEngine::Core::WorldObject::beginCollision()
{
	isColliding = true;
	collisionCount++;
}

void DreamEngine::Core::WorldObject::endCollision()
{
	collisionCount--;
	if (collisionCount == 0) {
		isColliding = 0;
	}
}
