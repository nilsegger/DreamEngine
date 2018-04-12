#pragma once

#include "CoreButton.h"
#include <SFML\Graphics.hpp>
#include "Mouse.h"
#include <assert.h>
#include "Camera.h"
#include "Pair.h"
namespace DreamEngine {

	struct MenuDef {
		Mouse * mouse = nullptr;
		Camera * camera = nullptr;
	};

	class Menu {
	public:
		Menu(MenuDef def);

		virtual void update();
		virtual void addButton(Core::Button * button);
	private:
		std::vector<Pair<Core::Button*, Pair<bool, bool>>> buttons; //bool 1 is for isHovering, bool2 isbeingClicked, preventing double events...
		Mouse * mouse;
		Camera * camera;
	};

};