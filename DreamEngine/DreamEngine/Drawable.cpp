#include "Drawable.h"

DreamEngine::Drawable::Drawable(DrawableDef def)
	:Core::Drawable(def), window(def.window)
{
}