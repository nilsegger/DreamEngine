#include "Animation.h"


DreamEngine::Animation::Animation(AnimationDefinition animationDefinition)
	:animationDefinition(animationDefinition), Object(animationDefinition)
{
}

DreamEngine::Animation::~Animation()
{
}

std::string DreamEngine::Animation::getName() const
{
	return animationDefinition.name;
}



sf::IntRect DreamEngine::Animation::update()
{
	if (frameTimer.getElapsedTime() >= animationDefinition.frame.duration / animationDefinition.speed) {

		if (animationDefinition.reverse == false) {
			animationDefinition.current++;
			if (animationDefinition.current == animationDefinition.framesCount && animationDefinition.loop) animationDefinition.current = 0;
			else if (animationDefinition.current == animationDefinition.framesCount) {
				//animation callback
			}
		}
		else {
			animationDefinition.current--;
			if (animationDefinition.current == -1 && animationDefinition.loop) animationDefinition.current = animationDefinition.framesCount-1;
			else if (animationDefinition.current == -1) {
				//animation callback
			}
		}
		frameTimer.restart();
	}

	return{ animationDefinition.frame.offset.x + animationDefinition.frame.size.x * animationDefinition.current, animationDefinition.frame.offset.y, animationDefinition.frame.size.x,animationDefinition.frame.size.y};
}
