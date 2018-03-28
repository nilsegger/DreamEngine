#pragma once

#include "WorldObject.h"

namespace DreamEngine {


	struct ActorDef : public Core::WorldObjectDef {

	};

	class Actor : public Core::WorldObject {
	public:
		Actor(ActorDef def);

		

	};

};