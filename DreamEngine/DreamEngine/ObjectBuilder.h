#pragma once

#include "CoreObjectBuilder.h"
#include "CoreWindow.h"
#include "CameraManager.h"
#include "CoreSceneManager.h"
#include "Objects.h"

namespace DreamEngine {

	struct ObjectBuilderDef {
		Core::Window * window = nullptr;
		Core::SceneManager * sceneManager = nullptr;
		CameraManager * cameraManager = nullptr;
	};

	class ObjectBuilder : public Core::ObjectBuilder {
	public:
		ObjectBuilder(ObjectBuilderDef def);
		// Inherited via ObjectBuilder
		virtual bool doesBuild(std::string type) override;

		void addBuildType(std::string type);

		Core::Window * window;
		Core::SceneManager * sceneManager;
		CameraManager * cameraManager;

	private:
		std::vector<std::string> buildTypes;
	};

};
