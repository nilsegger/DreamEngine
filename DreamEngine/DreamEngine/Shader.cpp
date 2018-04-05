#include "Shader.h"

DreamEngine::Shader::Shader(ShaderDef def)
	:Core::Object(def), path(def.path)
{
}

DreamEngine::Shader::~Shader()
{
	if (shader != nullptr) delete shader;
	shader = nullptr;
}

void DreamEngine::Shader::load()
{
	shader = new sf::Shader;
	/*if (!((*shader).loadFromFile(path + ".vert", path + ".frag"))) {
		std::cout << "Can't load shader '" << path << "'" << std::endl;
	}*/
	if (!((*shader).loadFromFile(path + ".frag", sf::Shader::Fragment))) {
		std::cout << "Can't load shader '" << path << "'" << std::endl;
	}
}

sf::Shader * DreamEngine::Shader::getShader()
{
	//assert(shader != nullptr); //Returing nullptr shader could cause an error
	return shader;
}
