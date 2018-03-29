#pragma once
#include "ObjectBuilder.h"
#include "Sprite.h"
#include "DefaultScene.h"
#include "Shader.h"
namespace DreamEngine {

	struct SpriteBuilderDef : public ObjectBuilderDef {

	};


	class SpriteBuilder : public ObjectBuilder {
	public:
		SpriteBuilder(SpriteBuilderDef def);

		// Inherited via ObjectBuilder
		virtual void build(DreamEngine::ObjectData data, std::string type) override;
	};


};


