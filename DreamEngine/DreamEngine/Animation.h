#pragma once

#include "CoreObject.h"
#include <SFML\Graphics.hpp>
#include "Timer.h"
#include <string>

namespace DreamEngine {

	struct Frame {
		float duration = 1.f;
		sf::Vector2i size = { 64,64 };
		sf::Vector2i offset;
	};

	struct AnimationDefinition : public DreamEngine::Core::ObjectDef {
		std::string name;
		Frame frame;

		int current = 0;
		int framesCount;
		int framesPerLine = 16;
		bool reverse = false;
		bool loop = true;
		float speed = 1.f;

		//AnimationCallback
	};

	class Animation : public DreamEngine::Core::Object
	{
	public:
		Animation(AnimationDefinition animationDefinition);
		~Animation();

		std::string getName() const;

		virtual sf::IntRect update();
	private:
		AnimationDefinition animationDefinition;
		Timer frameTimer;
	};

};