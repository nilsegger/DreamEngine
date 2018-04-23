#include "Builder.h"

DreamEngine::Builder::~Builder()
{
	for (int i = int(builders.size()) - 1; i >= 0; i--) {
		delete builders[i];
	}
}

void DreamEngine::Builder::build(std::vector<ObjectData> data, float * progress)
{

	if (int(data.size()) > 0) { if (builders.size() == 0) std::cout << "No Builders" << std::endl; }

	int size = int(data.size());
	for (int i = 0; i < size; i++) {
		std::string type = data[i].getString("type");
		if (type == "metadata") continue; //meta data
		for (int q = 0; q < int(builders.size()); q++) {
			if (builders[q]->doesBuild(type)) {
				builders[q]->build(data[i], type);
				break;
			}
			else if (q == int(builders.size()) - 1) {
				std::cout << "No builder found for object of type '" << type << "'" << std::endl;
			}
		}

		*progress = 100.f / size * (i + 1);
	}
	*progress = 100.f;
}

void DreamEngine::Builder::addBuilder(Core::ObjectBuilder * builder)
{
	builders.push_back(builder);
}
