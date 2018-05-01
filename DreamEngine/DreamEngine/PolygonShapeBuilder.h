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



};