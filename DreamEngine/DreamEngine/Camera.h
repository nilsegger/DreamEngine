#pragma once

#include <SFML\Graphics.hpp>
#include <Box2D\Box2D.h>
#include "Engine.h"
#include "CoreDrawable.h"


#define MAX_DRAWABLES 1000


namespace DreamEngine {


	struct CameraDef : public Core::ObjectDef {
		sf::RenderWindow * window = nullptr;
		sf::Vector2i windowSize = {1280, 720};
	};


	class Camera : public Core::Object
	{
	public:
		Camera(CameraDef cameraDefinition);
		~Camera();

		void move(sf::Vector2f offset);
		void setCameraScreenPosition(sf::Vector2f position);
		void setCameraWorldPosition(b2Vec2 position);
		void setViewport(float ratioX, float ratioY, float widthRatio, float heightRatio);
		void rotate(float degrees);
		void setRotation(float degrees);
		b2Vec2 getWindowWorldSize();
		sf::View getView() const;
		sf::Vector2f getScreenPosition() const;
		void draw(DreamEngine::Core::Drawable * drawable);
		void display();
	private:
		sf::RenderWindow * window;

		sf::Vector2f position;
		sf::Vector2f viewport;
		sf::Vector2i windowSize;
		sf::View view;

		DreamEngine::Core::Drawable * drawables[1000];
		int count = 0;

		
	};

}