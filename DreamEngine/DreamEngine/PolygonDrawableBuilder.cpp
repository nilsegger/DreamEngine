#include "PolygonDrawableBuilder.h"

PolygonDrawableBuilder::PolygonDrawableBuilder(PolygonDrawableBuilderDef polygonDrawableBuilderDef)
	:DreamEngine::ObjectBuilder(polygonDrawableBuilderDef)
{
	addBuildType("polygondrawable");
}

void PolygonDrawableBuilder::build(DreamEngine::ObjectData data, std::string type)
{
	DreamEngine::DefaultScene * scene = (DreamEngine::DefaultScene*)sceneManager->get(data.getInt("scene", false));
	PolygonDrawableDef polygonDrawableDef;
	//polygonDrawableDef.objectData = data;
	polygonDrawableDef.type = "polygondrawable";
	polygonDrawableDef.id = data.getInt("id", false);
	polygonDrawableDef.bodyPosition = { data.getFloat("bodyPositionX"), data.getFloat("bodyPositionY") };
	polygonDrawableDef.points = data.getInt("vertices");
	b2Vec2 vertices[DreamEngine::Engine::MAX_VERTICES];
	for (int i = 0; i < polygonDrawableDef.points; i++) {
		vertices[i].x = data.getFloat("verticeX" + std::to_string(i));
		vertices[i].y = data.getFloat("verticeY" + std::to_string(i));
	}
	polygonDrawableDef.relativePointsPositions = vertices;
	polygonDrawableDef.window = window;
	polygonDrawableDef.color = sf::Color::Green;
	scene->drawables->add(new PolygonDrawable(polygonDrawableDef), true);
}

DreamEngine::ObjectData PolygonDrawableBuilder::getExampleObject()
{
	DreamEngine::ObjectData data;
	data.setString("type", "polgyondrawable");
	data.setInt("id", 0);
	data.setInt("scene", 0);
	data.setb2Vec2("bodyPosition", b2Vec2{0.f,0.f});
	b2Vec2 vertices[4];
	vertices[0] = {0,0};
	vertices[1] = { 0.5f,0 };
	vertices[2] = { 0.5f,0.5f };
	vertices[3] = { 0,.5f };
	data.setb2Vec2Array("vertices", 4, vertices);
	return data;
}
