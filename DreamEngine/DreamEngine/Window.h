#pragma once

#include "CoreWindow.h"

#include <Box2D\Box2D.h>
#include "Drawable.h"
#include <SFML\Graphics.hpp>
#include "FPSCounter.h"
#include <iostream>
#include "Camera.h"
#include "CameraManager.h"

namespace DreamEngine {

	struct WindowDef {
		sf::Vector2u fontSize;
		std::string title;
		sf::Uint32 style;
		sf::ContextSettings contextSettings;
	};

	class Window : public Core::Window
	{
	public:
		Window(WindowDef def);
		~Window();

		// Inherited via Window
		virtual bool isOpen() const override;
		virtual void clear() override;
		virtual void display() override;
		virtual void draw(DreamEngine::Core::Drawable * drawable) override;
		virtual void close() override;
		virtual void show(bool flag = true) override;
		virtual sf::RenderWindow * getWindow() override;

		// Inherited via Window
		virtual std::string getTextEnteredUpdateCycle() override;
		virtual std::string getTextEnteredDrawCycle() override;
		virtual void updateDone() override;


		void setCameraManager(CameraManager * cameraManager);

		int getKeys();

		Timer frameTimer;
		FPSCounter fpsCounter;
	private:
		sf::RenderWindow * window;
		void events();
		CameraManager * cameraManager;

		sf::Vector2u fontSize;
		std::string title;
		sf::Uint32 style;
		sf::ContextSettings contextSettings;

		std::string textEnteredUpdate = "";
		std::string textEnteredDraw = "";

		int getKeysCurrent = 0;
		sf::Keyboard::Key pressedKeysDuringDrawCycle[1000];
		int pressedKeysDuringDrawCycleSize = 0;
	};

};