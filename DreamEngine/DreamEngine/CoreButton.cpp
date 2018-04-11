#include "CoreButton.h"

DreamEngine::Core::Button::Button(ButtonDef def)
	:rect(def.rect), Drawable(def)
{
}
