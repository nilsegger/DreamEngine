#pragma once

#include "CoreObject.h"
#include "ObjectData.h"

namespace DreamEngine::Core {

	struct DrawableDef : public ObjectDef {

	};

	class Drawable : public Object {
	public:
		Drawable(DrawableDef def);
		virtual void draw() = 0;
		virtual void onDestroy() = 0;
		virtual void load() = 0;
		virtual ObjectData save() = 0;
	};
};