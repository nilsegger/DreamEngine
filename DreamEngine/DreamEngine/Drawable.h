#pragma once

#include "CoreDrawable.h"
#include "CoreWindow.h"

namespace DreamEngine {

	struct DrawableDef : public Core::DrawableDef {
		Core::Window * window;
	};

	class Drawable : public Core::Drawable {
	public:
		Drawable(DrawableDef def);

	private:
		Core::Window * window;


	};

};
