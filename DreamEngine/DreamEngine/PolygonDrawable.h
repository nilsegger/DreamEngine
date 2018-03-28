#pragma once
#include "Engine.h"
#include "Drawable.h"

struct PolygonDrawableDef : public DreamEngine::DrawableDef {
	b2Vec2 * relativePointsPositions = nullptr;
	int points = 0;
	float angle = 0.f;
	sf::Color color = sf::Color::Black;
	b2Vec2 bodyPosition = {0.f,0.f};
};

class PolygonDrawable :
	public DreamEngine::Drawable
{
public:
	PolygonDrawable(PolygonDrawableDef polygonDrawableDefinition);
	~PolygonDrawable();


	void setAngle(float angle);
	void setPosition(b2Vec2 bodyPosition);
	virtual void setFillColor(sf::Color color);
	
	

	// Inherited via Drawable
	virtual void draw() override;
	virtual void onDestroy() override;
	virtual void load() override;
	virtual DreamEngine::ObjectData save() override;
private:
	PolygonDrawableDef polygonDrawableDefinition;
	sf::ConvexShape * polygon = new sf::ConvexShape;




};
