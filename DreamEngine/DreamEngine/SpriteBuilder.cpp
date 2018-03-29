#include "SpriteBuilder.h"

DreamEngine::SpriteBuilder::SpriteBuilder(SpriteBuilderDef def)
	:ObjectBuilder(def)
{
	addBuildType("default-sprite");
}

void DreamEngine::SpriteBuilder::build(DreamEngine::ObjectData data, std::string type)
{

	DefaultScene * scene = (DefaultScene*)sceneManager->get(data.getInt("scene"));

	SpriteDefiniton def;
	def.id = data.getInt("id", false);
	def.position = data.getVec2f("position");
	def.size = data.getVec2f("size");
	def.type = "default-sprite";
	def.window = window;
	def.animationManager = new AnimationManager;
	def.spritesheetDefinition.position =data.getVec2i("spritesheet-position");
	def.spritesheetDefinition.size = data.getVec2i("spritesheet-size");
	def.spritesheetDefinition.spritesheet = data.getString("spritesheet");
	Sprite * sprite = new Sprite(def);

	if (data.hasKey("shader")) {
		ShaderDef shaderDef;
		shaderDef.path = data.getString("shader");
		Shader * shader = new Shader(shaderDef);
		sprite->addShader(shader);
	}

	scene->drawables->add(sprite, true);

}
