#pragma once

#include "ObjectData.h"

namespace DreamEngine::Core {

	class Builder {
	public:
		virtual void build(std::vector<ObjectData> data, float * progress) = 0;
	};

};
