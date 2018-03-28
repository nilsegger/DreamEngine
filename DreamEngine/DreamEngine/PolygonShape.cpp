#include "PolygonShape.h"

PolygonShape::PolygonShape(PolygonShapeDef def)
	:body(def.body), DreamEngine::Shape(def), polygonDrawable(def.polygonDrawable), camera(def.cameraManager->get(DreamEngine::Cameras::WORLD))
{
	body->SetUserData(this);
}

void PolygonShape::instantiate(DreamEngine::ObjectData data)
{
}

void PolygonShape::onDestroy()
{
	body->SetUserData(nullptr);
	b2World * world = body->GetWorld();
	world->DestroyBody(body);
}

void PolygonShape::draw(float delta)
{
	assert(camera != nullptr);
	assert(polygonDrawable != nullptr);



	polygonDrawable->setPosition(body->GetPosition());
	polygonDrawable->setAngle(body->GetAngle());
	camera->draw(polygonDrawable);
}

void PolygonShape::update(float delta)
{
}

DreamEngine::ObjectData PolygonShape::save()
{
	return DreamEngine::ObjectData();
}

void PolygonShape::beginActorCollision(void * other, b2Contact * contact)
{
}

void PolygonShape::endActorCollision(void * other, b2Contact * contact)
{
}

void PolygonShape::beginShapeCollision(void * other, b2Contact * contact)
{
}

void PolygonShape::endShapeCollision(void * other, b2Contact * contact)
{
}
