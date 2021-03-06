#pragma once

#include "CoreDrawable.h"
#include "CoreWindow.h"

namespace DreamEngine {

	struct DrawableDef : public Core::DrawableDef {
		Core::Window * window = nullptr;
	};

	class Drawable : public Core::Drawable {
	public:
		Drawable(DrawableDef def);
		Core::Window * window;
	};

};
