#include "WorldObjectManager.h"

void DreamEngine::WorldObjectManager::draw(float delta)
{
	for (Core::WorldObject * w = (Core::WorldObject *)getFirst(); w != nullptr; w = (Core::WorldObject *)getNext()) w->draw(delta);
}

void DreamEngine::WorldObjectManager::update(float delta)
{
	for (Core::WorldObject * w = (Core::WorldObject *)getFirst(); w != nullptr; w = (Core::WorldObject *)getNext()) w->update(delta);
}

bool DreamEngine::WorldObjectManager::destroyObject(DreamEngine::Core::WorldObject * o)
{
	if (remove(o)) {
		o->onDestroy();
		delete o;
		return true;
	}
	return false;
}

void DreamEngine::WorldObjectManager::destroyObjects()
{
	for (Core::WorldObject * w = (Core::WorldObject *)getFirst(); w != nullptr; w = (Core::WorldObject *)getNext()) destroyObject(w);
}
