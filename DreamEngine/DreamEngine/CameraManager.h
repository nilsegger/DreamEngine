#pragma once

#include "ObjectManager.h"
#include "Camera.h"


namespace DreamEngine {

	enum Cameras {
		WORLD = 0, unfocusedPanel = 1, focusedPanel = 2, UI = 3
	};

	class CameraManager :
		public ObjectManager
	{
	public:
		CameraManager();
		~CameraManager();
		Camera * get(Cameras camera);
		void draw(sf::RenderWindow * window);
	};

};