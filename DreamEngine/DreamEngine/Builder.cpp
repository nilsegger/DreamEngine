#include "Builder.h"

void DreamEngine::Builder::build(std::vector<ObjectData> data, float * progress)
{

	if(int(data.size()) > 0) assert(builders.size() > 0);

	int size = int(data.size());
	for (int i = 0; i < size; i++) {
		OBJECTS type = OBJECTS(data[i].getInt("type"));
		std::cout << "Type is " << type << std::endl;
		if (type == -1) continue; //meta data
		for (int q = 0; q < int(builders.size()); q++) {
			if (builders[q]->doesBuild(type)) {
				builders[q]->build(data[i], type);
				std::cout << "Builder found" << std::endl;
				break;
			}
			else if (q == int(builders.size()) - 1) {
				std::cout << "No builder found for object of type " << type << std::endl;
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
