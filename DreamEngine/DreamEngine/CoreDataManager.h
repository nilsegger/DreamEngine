#pragma once

#include <vector>
#include "ObjectData.h"

namespace DreamEngine::Core {


	class DataManager {
		virtual void getObjectData(std::vector<ObjectData> * data, float * progress) = 0;
		virtual void startSaveChain() = 0;
		virtual void save(ObjectData objectData) = 0;
		virtual void save() = 0;
	};


};