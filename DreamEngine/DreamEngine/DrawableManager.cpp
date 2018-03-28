#include "DrawableManager.h"

void DreamEngine::DrawableManager::load(float * progress)
{
	for (Core::Drawable * o = (Core::Drawable*)getFirst(); o != nullptr; o = (Core::Drawable*)getNext()) {
		o->load();
	}
}

bool DreamEngine::DrawableManager::destroyObject(Core::Drawable * o)
{
	if (remove(o)) {
		o->onDestroy();
		delete o;
		return true;
	}
	return false;
}

bool DreamEngine::DrawableManager::destroyObjects()
{
	for (Core::Drawable * o = (Core::Drawable*)getFirst(); o != nullptr; o = (Core::Drawable*)getNext()) {
		destroyObject(o);
	}
	return true;
}
