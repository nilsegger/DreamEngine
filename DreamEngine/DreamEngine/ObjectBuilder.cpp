#include "ObjectBuilder.h"

DreamEngine::ObjectBuilder::ObjectBuilder(ObjectBuilderDef def)
	:window(def.window), sceneManager(def.sceneManager), cameraManager(def.cameraManager)
{
}

bool DreamEngine::ObjectBuilder::doesBuild(OBJECTS type)
{
	for (int i = 0; i < int(buildTypes.size()); i++) if (buildTypes[i] == type) return true;
	return false;
}

void DreamEngine::ObjectBuilder::addBuildType(OBJECTS type)
{
	buildTypes.push_back(type);
}