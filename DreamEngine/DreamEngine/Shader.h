#pragma once

#include <SFML\Graphics.hpp>
#include <string>
#include "CoreObject.h"
#include <assert.h>

#include <iostream>
namespace DreamEngine {

	struct ShaderDef : Core::ObjectDef {
		std::string path;
	};

	class Shader : public Core::Object  {

	public:
		Shader(ShaderDef def);

		void load();
		sf::Shader * getShader();
	private:
		sf::Shader * shader = nullptr;
		std::string path;
	};

};
