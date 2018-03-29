#include "Sprite.h"

DreamEngine::Sprite::Sprite(SpriteDefiniton spriteDefiniton)
	:Drawable(spriteDefiniton), spriteDefiniton(spriteDefiniton), animationManager(spriteDefiniton.animationManager), window(spriteDefiniton.window)
{
}

void DreamEngine::Sprite::setAnimation(std::string name)
{
	anim = animationManager->getAnimation(name);
}

void DreamEngine::Sprite::draw()
{
	if (anim != nullptr) rect->setTextureRect(anim->update());
	if(shader == nullptr) window->getWindow()->draw(*rect);
	else {
		shader->getShader()->setUniform("texture", *rect->getTexture());
		shader->getShader()->setUniform("width", rect->getSize().x);
		window->getWindow()->draw(*rect, shader->getShader());
	}
}

void DreamEngine::Sprite::onDestroy()
{
}

void DreamEngine::Sprite::load()
{
	
	if (!texture.loadFromFile(spriteDefiniton.spritesheetDefinition.spritesheet)) {
		std::cout << ("Failed to load spritesheet '" + spriteDefiniton.spritesheetDefinition.spritesheet + "'") << std::endl;
	}

	texture.setRepeated(false);
	texture.setSmooth(false);
	
	rect->setPosition(spriteDefiniton.position);
	rect->setSize(spriteDefiniton.size);
	
	rect->setTexture(&texture);
	rect->setTextureRect(sf::IntRect(spriteDefiniton.spritesheetDefinition.position.x, spriteDefiniton.spritesheetDefinition.position.y, spriteDefiniton.spritesheetDefinition.size.x, spriteDefiniton.spritesheetDefinition.size.y));

	if (shader != nullptr) shader->load();
}

DreamEngine::ObjectData DreamEngine::Sprite::save()
{
	return ObjectData();
}

void DreamEngine::Sprite::addShader(Shader * shader)
{
	this->shader = shader;
}

void DreamEngine::Sprite::setAngle(float angle)
{
	rect->setRotation(Engine::radianToDeg(angle));
}

void DreamEngine::Sprite::setPosition(b2Vec2 bodyPosition)
{
	rect->setPosition(Engine::worldToPixel(bodyPosition));
}

void DreamEngine::Sprite::setFillColor(sf::Color color)
{
}

