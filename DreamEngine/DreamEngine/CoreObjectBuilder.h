#pragma once

#include "Objects.h"
#include "ObjectData.h"
#include "Pair.h"

#include "UIElement.h"

namespace DreamEngine::Core {

	class ObjectBuilder {
	public:
		virtual bool doesBuild(std::string type) = 0;
		virtual void build(DreamEngine::ObjectData data, std::string type) = 0;
		virtual DreamEngine::ObjectData getExampleObject() = 0; //Used for editor
	};

};