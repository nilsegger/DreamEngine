#pragma once

#include "CoreObject.h"
#include <iostream>
#include <vector>

#define MAX_OBJECTS 1000

namespace DreamEngine {

	class ObjectManager
	{
	public:
		ObjectManager();
		~ObjectManager();

		bool add(Core::Object * o, bool fixedId = false);
		bool remove(Core::Object * o);
		Core::Object * get(int id);

		virtual void freeObjects();

		virtual Core::Object * getFirst();
		virtual Core::Object * getNext();

		int getSize() const;
	private:
		Core::Object * objects[MAX_OBJECTS];
		bool fixedIds[MAX_OBJECTS];

		int objectCount = 0;

		int freeSpace[MAX_OBJECTS];
		int freeSpaceCount = 0;
		bool isFreeSpace(int index);
		void addFreeSpaces(int start, int end);
		void removeFreeSpace(int index);

		int getCount = 0;
		int last = 0;
	};

};