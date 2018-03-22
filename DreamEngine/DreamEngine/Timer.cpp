#include "Timer.h"


void DreamEngine::Timer::start()
{
	restart();
}

void DreamEngine::Timer::restart()
{
	clock.restart();
}

float DreamEngine::Timer::getElapsedTime()
{
	return clock.getElapsedTime().asSeconds();
}
