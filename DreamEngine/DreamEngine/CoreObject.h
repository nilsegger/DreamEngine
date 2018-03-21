#pragma once

#include "Objects.h"

namespace DreamEngine::Core {

	struct ObjectDef {
		int id = -1;
		OBJECTS type = OBJECT;
	};

	class Object
	{
	public:
		Object(ObjectDef def);

		int id;
		OBJECTS type;
	};

}