#include "CoreButton.h"


DreamEngine::Core::Button::Button(ButtonDef def)
	:rect(def.rect), Drawable(def)
{
}
bool DreamEngine::Core::Button::onButton(sf::Vector2f point)
{
	return (point.x >= rect.left && point.x <= rect.left + rect.width && point.y >= rect.top && point.y <= rect.top + rect.height);
}
