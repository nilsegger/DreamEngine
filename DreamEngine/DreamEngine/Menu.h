#pragma once

#include "CoreButton.h"
#include <SFML\Graphics.hpp>
#include "Mouse.h"

namespace DreamEngine {

	struct MenuDef {
		Mouse * mouse;
	};

	class Menu {
	public:
		virtual void update();
	private:
		std::vector<Core::Button> buttons;
		Mouse * mouse;
	};

};