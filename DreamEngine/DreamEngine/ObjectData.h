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

		void add(Pair<std::string, std::string> pair);

		void setString(std::string key, std::string val);
		void setInt(std::string key, int val);
		void setFloat(std::string key, float val);
		void setBool(std::string key, bool flag);
		void setb2Vec2(std::string key, b2Vec2 val);
		void setVec2f(std::string key, sf::Vector2f val);
		void setVec2i(std::string key, sf::Vector2i val);

		void print();

		std::string toString();
	private:
		std::vector<Pair<std::string, std::string>> data;
		int getSize();
		int last = 0;

		int getIndexOfKey(std::string key);

	};

};
