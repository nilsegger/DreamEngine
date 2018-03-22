#include "FPSCounter.h"



DreamEngine::FPSCounter::FPSCounter()
{
}


DreamEngine::FPSCounter::~FPSCounter()
{
}

int DreamEngine::FPSCounter::getFrames()
{
	count++;
	if (timer.getElapsedTime() >= 1.f) {
		timer.restart();
		frames = count;
		count = 0;
	}
	return frames;
}
