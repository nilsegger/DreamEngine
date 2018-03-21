#include "ObjectData.h"

DreamEngine::ObjectData::ObjectData()
{
}

DreamEngine::ObjectData::~ObjectData()
{
}

bool DreamEngine::ObjectData::hasKey(std::string key, bool optional)
{
	int size = int(data.size());
	for (int i = 0; i < size; i++) {
		if (data[i].a == key) {
			last = i;
			return true;
		}
	}
	if (!optional) std::cout << "Key '" << key << "' not found." << std::endl;
	return false;
}

std::string DreamEngine::ObjectData::getString(std::string key, bool optional)
{
	if (!hasKey(key, optional)) return "0";
	return data[last].b;
}

int DreamEngine::ObjectData::getInt(std::string key, bool optional)
{
	return std::stoi(getString(key, optional));
}

bool DreamEngine::ObjectData::getBool(std::string key, bool optional)
{
	if (!hasKey(key, optional)) return false;
	return getInt(key, optional) != 0;
}

float DreamEngine::ObjectData::getFloat(std::string key, bool optional)
{
	return getInt(key) / INT_TO_FLOAT;
}

void DreamEngine::ObjectData::add(Pair<std::string, std::string> pair)
{
	data.push_back(pair);
}

void DreamEngine::ObjectData::setString(std::string key, std::string val)
{
	int index = getIndexOfKey(key);
	if (index != -1) data[index].b = val;
	else add({ key, val });
}

void DreamEngine::ObjectData::setInt(std::string key, int val)
{
	setString(key, std::to_string(val));
}

void DreamEngine::ObjectData::setFloat(std::string key, float val)
{
	setInt(key, int(val * INT_TO_FLOAT));
}

void DreamEngine::ObjectData::setBool(std::string key, bool flag)
{
	if (flag) setInt(key, 1);
	else setInt(key, 0);
}

void DreamEngine::ObjectData::print()
{
	std::cout << "---" << std::endl;
	for (int i = 0; i < getSize(); i++) {
		std::cout << data[i].a << ": " << data[i].b << std::endl;
	}
	std::cout << "---" << std::endl;
}

std::string DreamEngine::ObjectData::toString()
{
	std::string objectData = "";

	for (int i = 0; i < getSize() - 1; i++) {
		objectData = objectData + data[i].a + "\t" + data[i].b + "\n";
	}
	objectData = objectData + data[getSize() - 1].a + "\t" + data[getSize() - 1].b;
	return objectData;
}

int DreamEngine::ObjectData::getSize()
{
	return int(data.size());
}

int DreamEngine::ObjectData::getIndexOfKey(std::string key)
{
	if (hasKey(key)) return last;
	return -1;
}