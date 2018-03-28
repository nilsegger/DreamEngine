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
	virtual void build(DreamEngine::ObjectData data, OBJECTS type) override;

};
