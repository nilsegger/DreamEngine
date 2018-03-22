#include "AnimationManager.h"



DreamEngine::AnimationManager::AnimationManager()
{
}


DreamEngine::AnimationManager::~AnimationManager()
{
}

DreamEngine::Animation * DreamEngine::AnimationManager::getAnimation(std::string name)
{
	for (DreamEngine::Animation * a = (DreamEngine::Animation*)getFirst(); a != nullptr; a = (DreamEngine::Animation*)getNext()) {
		if (a->getName() == name) return a;
	}
	return nullptr;
}

DreamEngine::Animation * DreamEngine::AnimationManager::get(int index)
{
	return (Animation*)ObjectManager::get(index);
}
