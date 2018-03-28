#pragma once

#include "ObjectManager.h"
#include "CoreDrawable.h"

namespace DreamEngine {

	class DrawableManager : public ObjectManager {

	public:

		void load(float * progress);
		bool destroyObject(Core::Drawable * o);
		bool destroyObjects();

	};

}