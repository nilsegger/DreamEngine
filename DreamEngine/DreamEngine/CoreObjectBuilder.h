#pragma once

#include "Objects.h"
#include "ObjectData.h"

namespace DreamEngine::Core {

	class ObjectBuilder {
	public:
		virtual bool doesBuild(std::string type) = 0;
		virtual void build(DreamEngine::ObjectData data, std::string type) = 0;
	};

};