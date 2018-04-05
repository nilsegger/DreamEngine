#include "DataManager.h"

DreamEngine::DataManager::DataManager(DataManagerDef def)
	:savePath(def.savePath), loadPath(def.loadPath)
{
}

void DreamEngine::DataManager::read(std::vector<ObjectData> * data, float * progress)
{
	file.open(loadPath, std::fstream::in | std::fstream::app);

	file.seekg(0, std::ios_base::end);
	int max = int(file.tellg());
	file.seekg(0, std::ios_base::beg);
	data->push_back(ObjectData());
	
	int index = 0;
	std::string line;
	while (std::getline(file, line))
	{
		
		std::istringstream iss(line);
		std::string a, b;
		if (!(iss >> a >> b)) break; //End of line
		if (a == "-" && b == "-") {
			data->push_back(ObjectData());
			index++;
		}
		else {
			(*data)[index].add({ a,b });
		}
		*progress = 100.f / max * int(file.tellg());
	}

	if (debugPrint) {
		for (int i = 0; i < int(data->size()); i++) {
			(*data)[i].print();
		}
	}
	file.close();
	*progress = 100.f;
}

void DreamEngine::DataManager::save()
{
	std::string data = "";
	for (int i = 0; i < int(dataToSave->size()); i++) {
		data = data + (*dataToSave)[i].toString() + "\n-\t-\n";
	}
	file.open(savePath, std::fstream::out);
	file << data;
	file.close();
}

void DreamEngine::DataManager::getObjectData(std::vector<ObjectData> * data, float * progress)
{
	read(data, progress);
	//return (*data);
}

void DreamEngine::DataManager::startSaveChain()
{
	if (dataToSave != nullptr) delete dataToSave;
	dataToSave = new std::vector<ObjectData>();
}

void DreamEngine::DataManager::save(ObjectData objectData)
{
	dataToSave->push_back(objectData);
}

void DreamEngine::DataManager::saveTo(std::string path)
{
	savePath = path;
}

void DreamEngine::DataManager::setDebugPrint(bool flag)
{
	debugPrint = flag;
}
