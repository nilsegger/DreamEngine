#pragma once

#include "CoreObject.h"
#include "CoreDataManager.h"

namespace DreamEngine::Core {


	struct  SceneDef : public ObjectDef
	{

	};

	class Scene : public Object {

		Scene(SceneDef def);

		virtual void update(float delta) = 0;
		virtual void draw(float delta) = 0;
		virtual void destroy() = 0;
		virtual void load(float * progress) = 0;
		virtual void start() = 0;
		virtual void end() = 0;
		virtual void save(Core::DataManager * dataManager) = 0;

	};


}