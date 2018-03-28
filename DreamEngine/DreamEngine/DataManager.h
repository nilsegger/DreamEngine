#pragma once

#include "CoreDataManager.h"
#include "ObjectData.h"
#include <sstream>
#include "Engine.h"
#include <fstream>

namespace DreamEngine {

	struct DataManagerDef {
		std::string savePath;
		std::string loadPath;
	};

	class DataManager : public Core::DataManager
	{
	public:
		DataManager(DataManagerDef def);

		// Inherited via Core::DataManager
		virtual void getObjectData(std::vector<ObjectData> * data, float * progress) override;

		virtual void startSaveChain();
		virtual void save(ObjectData objectData);
		virtual void save() override;


		virtual void saveTo(std::string path);

		void setDebugPrint(bool flag);
	private:
		std::vector<ObjectData> * data;
		void read(std::vector<ObjectData> * data, float * progress);

		std::vector<ObjectData> * dataToSave;

		std::fstream file;

		std::string savePath;
		std::string loadPath;

		bool debugPrint = false;
	};

};