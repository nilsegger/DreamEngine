#include "ObjectBuilder.h"

DreamEngine::ObjectBuilder::ObjectBuilder(ObjectBuilderDef def)
	:window(def.window), sceneManager(def.sceneManager), cameraManager(def.cameraManager)
{
}

bool DreamEngine::ObjectBuilder::doesBuild(std::string type)
{
	for (int i = 0; i < int(buildTypes.size()); i++) if (buildTypes[i] == type) return true;
	return false;
}

void DreamEngine::ObjectBuilder::addBuildType(std::string type)
{
	buildTypes.push_back(type);
}