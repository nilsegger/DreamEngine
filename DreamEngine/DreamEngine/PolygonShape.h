#pragma once


#include "PolygonDrawable.h"
#include "DreamEngine.h"

struct PolygonShapeDef : public DreamEngine::ShapeDef {
	b2Body * body;
	PolygonDrawable * polygonDrawable;
	DreamEngine::CameraManager * cameraManager;
};

class PolygonShape : public DreamEngine::Shape {
public:
	PolygonShape(PolygonShapeDef def);

	// Inherited via Shape
	virtual void instantiate(DreamEngine::ObjectData data) override;
	virtual void onDestroy() override;
	virtual void draw(float delta) override;
	virtual void update(float delta) override;
	virtual DreamEngine::ObjectData save() override;
	virtual void beginActorCollision(void * other, b2Contact * contact) override;
	virtual void endActorCollision(void * other, b2Contact * contact) override;
	virtual void beginShapeCollision(void * other, b2Contact * contact) override;
	virtual void endShapeCollision(void * other, b2Contact * contact) override;

	b2Body * body = nullptr;
	PolygonDrawable * polygonDrawable = nullptr;
	DreamEngine::Camera * camera = nullptr;
};