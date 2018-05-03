#pragma once

#include <vector>
#include "Objects.h"
#include <iostream>
#include <string>
#include "Pair.h"
#include <Box2D\Box2D.h>
#include <SFML\Graphics.hpp>
#define INT_TO_FLOAT 1000.f

namespace DreamEngine {

	enum ObjectDataType {
		NONE, INT, FLOAT, STRING, BOOL, B2VEC2_X, B2VEC2_Y, VEC2F_X, VEC2F_Y, VEC2I_X, VEC2I_Y, B2VEC2_ARRAY_COUNT, B2VEC2_ARRAY_VALUE_X, B2VEC2_ARRAY_VALUE_Y
	};

	class ObjectData {
	public:
		ObjectData();
		~ObjectData();

		bool hasKey(std::string key, bool optional = true);

		std::string getString(std::string key, bool optional = true);
		int getInt(std::string key, bool optional = true);
		bool getBool(std::string key, bool optional = true);
		float getFloat(std::string key, bool optional = true);
		b2Vec2 getb2Vec2(std::string key, bool optional = true);
		sf::Vector2f getVec2f(std::string key, bool optional = true);
		sf::Vector2i getVec2i(std::string key, bool optional = true);
		std::vector<b2Vec2> getb2Vec2Array(std::string key, bool optional = true);

		void add(Trio<std::string, std::string, ObjectDataType> pair);

		void setString(std::string key, std::string val, ObjectDataType type = NONE);
		void setInt(std::string key, int val, ObjectDataType type = NONE);
		void setFloat(std::string key, float val, ObjectDataType type = NONE);
		void setBool(std::string key, bool flag, ObjectDataType type = NONE);
		void setb2Vec2(std::string key, b2Vec2 val, ObjectDataType type = NONE);
		void setVec2f(std::string key, sf::Vector2f val, ObjectDataType type = NONE);
		void setVec2i(std::string key, sf::Vector2i val, ObjectDataType type = NONE);
		void setb2Vec2Array(std::string key, int count, b2Vec2 * arr, ObjectDataType type = NONE);
		void print();

		std::vector<Trio<std::string, std::string, ObjectDataType>> getData(); //Key, value, Type

		std::string toString();
	private:
		std::vector<Trio<std::string, std::string, ObjectDataType>> data;
		int getSize();
		int last = 0;

		int getIndexOfKey(std::string key);

	};

};
