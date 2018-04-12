#include "ButtonsManager.h"

DreamEngine::Menu::Menu(MenuDef def)
	:mouse(def.mouse), camera(def.camera)
{
}

void DreamEngine::Menu::update()
{
	assert(mouse != nullptr);
	assert(camera != nullptr);

	for (int i = 0; i < int(buttons.size()); i++) {
		if (buttons[i].a->onButton(mouse->getMouseScreenPosition(camera))) {
			if (buttons[i].a->isActive == false) continue;
			if (mouse->leftIsClicked()) {
				if(buttons[i].b.b == false) buttons[i].a->onClick();
				buttons[i].b.b = true;
			}
			else {
				if (buttons[i].b.b == true) buttons[i].a->onEndClick();
				buttons[i].b.b = false;
			}
			if(buttons[i].b.a == false) buttons[i].a->onMouseOn();
			buttons[i].b.a = true;
		}
		else {
			if (buttons[i].b.a == true) buttons[i].a->onMouseLeave();
			buttons[i].b.a = false;
		}
	}
}

void DreamEngine::Menu::addButton(Core::Button * button)
{
	buttons.push_back({button,{false,false}});
}
