#include "ObjectManager.h"

DreamEngine::ObjectManager::ObjectManager()
{
	for (int i = 0; i < MAX_OBJECTS; i++) objects[i] = nullptr;
	for (int i = 0; i < MAX_OBJECTS; i++) fixedIds[i] = false;
}


DreamEngine::ObjectManager::~ObjectManager()
{
}

bool DreamEngine::ObjectManager::add(Core::Object * o, bool fixedId)
{
	if (fixedId == false) {
		if (objectCount >= MAX_OBJECTS) {
			std::cerr << "Max objects exceeded... (Max: " << MAX_OBJECTS << ")" << std::endl;
			return false;
		}
		if (o->id != -1) {
			std::cerr << "Object with id " << o->id << " can't be added twice. (New Object type: " << o->type << ") (Object already has an id... Forgot to set fixed id flag to true?)" << std::endl;
			return false;
		}

		int index = objectCount;
		if (freeSpaceCount > 0) {
			freeSpaceCount--;
			index = freeSpace[freeSpaceCount];
		}
		o->id = index;
		objects[index] = o;
		fixedIds[index] = false;
		objectCount++;
		return true;
	}
	else {
		if (!(o->id >= 0 && o->id < MAX_OBJECTS)) {
			std::cout << "Fixed id isnt in index range. (" << o->id << ")" << std::endl;
			return false;
		}
		int index = o->id;
		if (objects[index] != nullptr) {
			if (fixedIds[index] == true) {
				std::cout << "Two objects with fixed id have the same id. (" << o->id << ")" << std::endl;
				return false;
			}
			else {
				Core::Object * temp = objects[index];
				remove(objects[index]);
				removeFreeSpace(index);
				add(temp);
			}
		}
		objects[index] = o;
		fixedIds[index] = true;
		objectCount++;
		addFreeSpaces(0, index);
		return true;
	}
}

DreamEngine::Core::Object * DreamEngine::ObjectManager::get(int id)
{
	if (id < MAX_OBJECTS) return objects[id];
	return nullptr;
}

void DreamEngine::ObjectManager::freeObjects()
{
	for (Core::Object * o = getFirst(); o != nullptr; o = getNext()) {
		o->id = -1;
	}
	freeSpaceCount = 0;
	objectCount = 0;
}

DreamEngine::Core::Object * DreamEngine::ObjectManager::getFirst()
{
	if (objectCount == 0) return nullptr;
	for (int i = 0; i < MAX_OBJECTS; i++) {
		if (objects[i] != nullptr) {
			last = i;
			getCount = 1;
			return objects[i];
		}
	}
	std::cout << "ObjectCount is greater than 0 but no object was found." << std::endl;
	return nullptr;
}

DreamEngine::Core::Object * DreamEngine::ObjectManager::getNext()
{
	if (getCount == objectCount) return nullptr;
	for (int i = last + 1; i < MAX_OBJECTS; i++) {
		if (objects[i] != nullptr) {
			last = i;
			getCount++;
			return objects[i];
		}
	}
	std::cout << "Haven't reached end but can't seem to find next Object..." << std::endl;
	return nullptr;
}

int DreamEngine::ObjectManager::getSize() const
{
	return objectCount;
}

bool DreamEngine::ObjectManager::isFreeSpace(int index)
{
	for (int i = 0; i < freeSpaceCount; i++) {
		if (freeSpace[i] == index) return true;
	}
	return false;
}

void DreamEngine::ObjectManager::addFreeSpaces(int start, int end)
{
	for (int i = start; i < end; i++) {
		if (objects[i] == nullptr) {
			if (!isFreeSpace(i)) {
				freeSpace[freeSpaceCount] = i;
				freeSpaceCount++;
			}
		}
	}
}

void DreamEngine::ObjectManager::removeFreeSpace(int index)
{
	int freeSpaceIndex = -1;
	for (int i = 0; i < freeSpaceCount; i++) {
		if (freeSpace[i] == index) freeSpaceIndex = i;
	}
	if (freeSpaceIndex == -1) return;
	freeSpaceCount--;
	freeSpace[freeSpaceIndex] = freeSpace[freeSpaceCount];
}

bool DreamEngine::ObjectManager::remove(DreamEngine::Core::Object * o)
{
	if (o->id == -1) {
		std::cerr << "Object can't be removed without having an id." << std::endl;
		return false;
	}
	int index = o->id;
	o->id = -1;
	freeSpace[freeSpaceCount] = index;
	freeSpaceCount++;
	objects[index] = nullptr;
	objectCount--;
	getCount--;

	/*
	Needed For GetNext...
	So were at object 0 with ObjectCount 2, ->delete it but GetCount still gets increased, so were at objectCount 1 with GetCount 1,
	now objectCount == GetCount and we step out of the loop without touching the second object,
	but because we want to reach the second object aswell, we decrease getCount here
	*/

	return true;
}