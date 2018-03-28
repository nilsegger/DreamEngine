#include "PolygonDrawable.h"

PolygonDrawable::PolygonDrawable(PolygonDrawableDef polygonDrawableDefinition)
	:DreamEngine::Drawable(polygonDrawableDefinition), polygonDrawableDefinition(polygonDrawableDefinition)
{
	polygon->setPointCount(polygonDrawableDefinition.points);
	for (int i = 0; i < polygonDrawableDefinition.points; i++, polygonDrawableDefinition.relativePointsPositions++) polygon->setPoint(i, DreamEngine::Engine::worldToPixel(*polygonDrawableDefinition.relativePointsPositions));
	polygon->setRotation(polygonDrawableDefinition.angle * 57.2958f); // To Degrees
	polygon->setOutlineColor(polygonDrawableDefinition.color);
	polygon->setOutlineThickness(1);
	polygon->setPosition(DreamEngine::Engine::worldToPixel(polygonDrawableDefinition.bodyPosition));
}

PolygonDrawable::~PolygonDrawable()
{
}

void PolygonDrawable::setAngle(float angle)
{
	polygon->setRotation(DreamEngine::Engine::radianToDeg(angle));
}

void PolygonDrawable::setPosition(b2Vec2 bodyPosition)
{
	polygon->setPosition(DreamEngine::Engine::worldToPixel(bodyPosition));
}

void PolygonDrawable::draw()
{
	window->getWindow()->draw(*polygon);
}

void PolygonDrawable::setFillColor(sf::Color color)
{
	polygon->setFillColor(color);
}

void PolygonDrawable::onDestroy()
{
}

void PolygonDrawable::load()
{

}

DreamEngine::ObjectData PolygonDrawable::save()
{
	return DreamEngine::ObjectData();
}