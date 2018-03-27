#pragma once

#include "Objects.h"
#include "ObjectData.h"

namespace DreamEngine::Core {

	class ObjectBuilder {
	public:
		virtual bool doesBuild(OBJECTS type) = 0;
		virtual void build(ObjectData data, OBJECTS type) = 0;
	};

};