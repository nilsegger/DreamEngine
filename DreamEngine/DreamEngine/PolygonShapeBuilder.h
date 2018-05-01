#pragma once

#include "DreamEngine.h"
#include "PolygonShape.h"
#include "BodyBuilder.h"

struct PolygonShapeBuilderDef : public DreamEngine::ObjectBuilderDef {

};

class PolygonShapeBuilder : public DreamEngine::ObjectBuilder {

public:
	PolygonShapeBuilder(PolygonShapeBuilderDef def);


	// Inherited via ObjectBuilder
	virtual void build(DreamEngine::ObjectData data, std::string type) override;


	// Inherited via ObjectBuilder
	virtual std::vector<Trio<std::string, DreamEngine::UserInterface::UIElementType, std::string>> getNecessaryObjectMembers() override;

	virtual DreamEngine::ObjectData createObjectDataFromNecessaryObjectMembers(std::vector<Trio<std::string, DreamEngine::UserInterface::UIElementType, std::string>>) override;

};