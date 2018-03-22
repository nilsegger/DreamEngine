#pragma once
#include "ObjectManager.h"
#include "Animation.h"


namespace DreamEngine {

	class AnimationManager :
		public DreamEngine::ObjectManager
	{
	public:
		AnimationManager();
		~AnimationManager();

		Animation * getAnimation(std::string name);
		Animation * get(int index);

	};

};