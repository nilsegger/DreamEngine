#pragma once

namespace DreamEngine {

	class Launchable {
	public:
		virtual void init() = 0;
		virtual void end() = 0;
		virtual bool update() = 0; //return true to continue; otherwise main program will exit loop
	};

};
