#pragma once

#include "Objects.h"
#include <string>

namespace DreamEngine::Core {

	struct ObjectDef {
		int id = -1;
		std::string type = "Default Object";
	};

	class Object
	{
	public:
		Object(ObjectDef def);

		int id;
		std::string type = "Default Object";
	};

}