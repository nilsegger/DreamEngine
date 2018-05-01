#pragma once

#include "ObjectBuilder.h"
#include "PolygonDrawable.h"
#include "DefaultScene.h"

struct PolygonDrawableBuilderDef : public DreamEngine::ObjectBuilderDef {

};

class PolygonDrawableBuilder : public DreamEngine::ObjectBuilder
{
public:
	PolygonDrawableBuilder(PolygonDrawableBuilderDef polygonDrawableBuilderDef);

	// Inherited via ObjectBuilder
	virtual void build(DreamEngine::ObjectData data, std::string type) override;


	// Inherited via ObjectBuilder
	virtual std::vector<Trio<std::string, DreamEngine::UserInterface::UIElementType, std::string>> getNecessaryObjectMembers() override;

	virtual DreamEngine::ObjectData createObjectDataFromNecessaryObjectMembers(std::vector<Trio<std::string, DreamEngine::UserInterface::UIElementType, std::string>>) override;

};
