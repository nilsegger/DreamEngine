#include "ObjectData.h"

DreamEngine::ObjectData::ObjectData()
{
}

DreamEngine::ObjectData::~ObjectData()
{
}

bool DreamEngine::ObjectData::hasKey(std::string key, bool optional)
{
	int fontSize = int(data.size());
	for (int i = 0; i < fontSize; i++) {
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
	return getInt(key, optional) / INT_TO_FLOAT;
}

b2Vec2 DreamEngine::ObjectData::getb2Vec2(std::string key, bool optional)
{
	return b2Vec2{getFloat( key + "X" ,optional), getFloat( key + "Y", optional)};
}

sf::Vector2f DreamEngine::ObjectData::getVec2f(std::string key, bool optional)
{
	return sf::Vector2f(getFloat(key+"X", optional), getFloat(key + "Y", optional));
}

sf::Vector2i DreamEngine::ObjectData::getVec2i(std::string key, bool optional)
{
	return sf::Vector2i(getInt(key + "X", optional), getInt(key + "Y", optional));
}

std::vector<b2Vec2> DreamEngine::ObjectData::getb2Vec2Array(std::string key, bool optional)
{

	int size = getInt(key, optional);
	std::vector<b2Vec2> result;
	for (int i = 0; i < size; i++) {
		result.push_back({getFloat(key + "X" + std::to_string(i)), getFloat(key + "Y" + std::to_string(i)) });
	}
	return result;
}

void DreamEngine::ObjectData::add(Trio<std::string, std::string, ObjectDataType> pair)
{
	data.push_back(pair);
}

void DreamEngine::ObjectData::setString(std::string key, std::string val, ObjectDataType type)
{
	int index = getIndexOfKey(key);
	if (index != -1) data[index].b = val;
	else {
		if(type == NONE) add({ key, val, STRING });
		else add({ key, val, type });
	}
}

void DreamEngine::ObjectData::setInt(std::string key, int val, ObjectDataType type)
{
	if(type == NONE) setString(key, std::to_string(val), INT);
	else setString(key, std::to_string(val), type);
}

void DreamEngine::ObjectData::setFloat(std::string key, float val, ObjectDataType type)
{
	if(type == NONE ) setInt(key, int(val * INT_TO_FLOAT), FLOAT);
	else setInt(key, int(val * INT_TO_FLOAT), type);
}

void DreamEngine::ObjectData::setBool(std::string key, bool flag, ObjectDataType type)
{
	if (flag) setInt(key, 1, BOOL);
	else setInt(key, 0, BOOL);
}

void DreamEngine::ObjectData::setb2Vec2(std::string key, b2Vec2 val, ObjectDataType type)
{
	setFloat(key + "X", val.x, B2VEC2_X);
	setFloat(key + "Y", val.y, B2VEC2_Y);
}

void DreamEngine::ObjectData::setVec2f(std::string key, sf::Vector2f val, ObjectDataType type)
{
	setFloat(key + "X", val.x, VEC2F_X);
	setFloat(key + "Y", val.y, VEC2F_Y);
}

void DreamEngine::ObjectData::setVec2i(std::string key, sf::Vector2i val, ObjectDataType type)
{
	setInt(key + "X", val.x, VEC2I_X);
	setInt(key + "Y", val.y, VEC2I_Y);
}

void DreamEngine::ObjectData::setb2Vec2Array(std::string key, int count, b2Vec2 * arr, ObjectDataType type)
{
	setInt(key, count, B2VEC2_ARRAY_COUNT);
	for (int i = 0; i < count; i++, arr++) {
		setFloat(key + "X" + std::to_string(i), (*arr).x, B2VEC2_ARRAY_VALUE_X);
		setFloat(key + "Y" + std::to_string(i), (*arr).y, B2VEC2_ARRAY_VALUE_Y);
	}
}

void DreamEngine::ObjectData::print()
{
	std::cout << "---" << std::endl;
	for (int i = 0; i < getSize(); i++) {
		std::cout << data[i].a << ": " << data[i].b << std::endl;
	}
	std::cout << "---" << std::endl;
}

std::vector<Trio<std::string, std::string, DreamEngine::ObjectDataType>> DreamEngine::ObjectData::getData()
{
	return data;
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