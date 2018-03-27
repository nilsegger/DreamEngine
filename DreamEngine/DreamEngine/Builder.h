#pragma once

#include <SFML\Graphics.hpp>
#include "ObjectData.h"
#include "Engine.h"
#include <Box2D\Box2D.h>
#include "CameraManager.h"
#include "SceneManager.h"

namespace DreamEngine {

	struct BuilderComponents {
		SceneManager * sceneManager;
		sf::RenderWindow * window;
		CameraManager * cameraManager;
	};

	class CustomBuilder {
	public:
		CustomBuilder(BuilderComponents builderComponents);
		virtual bool doesBuild(ObjectType type);
		virtual void build(ObjectData data, ObjectType type) = 0;
		BuilderComponents builderComponents;

		void addBuildType(ObjectType type);
	private:
		std::vector<ObjectType> buildTypes;
	};

};