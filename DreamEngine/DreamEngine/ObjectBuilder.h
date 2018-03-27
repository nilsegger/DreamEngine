#pragma once

#include "CoreObjectBuilder.h"
#include "CoreWindow.h"
#include "CameraManager.h"
#include "CoreSceneManager.h"
#include "Objects.h"

namespace DreamEngine {

	struct ObjectBuilderDef {
		Core::Window * window;
		Core::SceneManager * sceneManager;
		CameraManager * cameraManager;
	};

	class ObjectBuilder : public Core::ObjectBuilder {
	public:
		ObjectBuilder(ObjectBuilderDef def);
		// Inherited via ObjectBuilder
		virtual bool doesBuild(OBJECTS type) override;

		void addBuildType(OBJECTS type);

		Core::Window * window;
		Core::SceneManager * sceneManager;
		CameraManager * cameraManager;

	private:
		std::vector<OBJECTS> buildTypes;
	};

};
