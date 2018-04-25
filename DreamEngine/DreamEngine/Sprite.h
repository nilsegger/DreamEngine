#pragma once
#include "Drawable.h"
#include "Engine.h"

#include "AnimationManager.h"
#include "Shader.h"
#include "CoreWindow.h"
namespace DreamEngine {

	struct TextureDefinition {

	};

	struct SpritesheetDefinition {
		std::string spritesheet;
		sf::Vector2i position;
		sf::Vector2i fontSize;

		TextureDefinition textureDefinition;

		//Animations animations;
	};

	struct SpriteDefiniton : public DrawableDef {
		SpritesheetDefinition spritesheetDefinition;

		sf::Vector2f position;
		sf::Vector2f fontSize;

		AnimationManager * animationManager;

		DreamEngine::Core::Window * window;
	};

	class Sprite :
		public DreamEngine::Drawable
	{
	public:
		Sprite(SpriteDefiniton spriteDefiniton);

		SpriteDefiniton spriteDefiniton;

		void setAnimation(std::string name);

		void setAngle(float angle);
		void setPosition(b2Vec2 bodyPosition);
		void setFillColor(sf::Color color);

		// Inherited via Drawable
		virtual void draw() override;
		virtual void onDestroy() override;
		virtual void load() override;
		virtual ObjectData save() override;

		void addShader(Shader * shader);
	private:
		sf::RectangleShape * rect = new sf::RectangleShape;
		sf::Texture texture;
		Animation * anim;
		AnimationManager * animationManager;
		Core::Window * window;
		Shader * shader;
	};

};