#pragma once
#include "Timer.h"

namespace DreamEngine {

	class FPSCounter
	{
	public:
		FPSCounter();
		~FPSCounter();
		int getFrames();
	private:
		Timer timer;
		int count = 0;
		int frames = 0;
	};

}