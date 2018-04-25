#pragma once



#include "Drawable.h"

namespace DreamEngine {

	struct ButtonDef : public DrawableDef {

	};

	class Button : public Drawable {
		Button(ButtonDef def);
	};

}

