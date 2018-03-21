#pragma once

#include "WorldObject.h"
#include "Actor.h"

namespace DreamEngine {

	struct ShapeDef : public Core::WorldObjectDef {

	};

	class Shape : public Core::WorldObject {
	public:
		Shape(ShapeDef def);

		Actor * parent;

	};

};