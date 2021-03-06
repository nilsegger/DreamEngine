#include "PolygonShapeBuilder.h"

PolygonShapeBuilder::PolygonShapeBuilder(PolygonShapeBuilderDef def)
	:DreamEngine::ObjectBuilder(def)
{
	addBuildType("polygonshape");
}

void PolygonShapeBuilder::build(DreamEngine::ObjectData data, std::string type)
{
	DreamEngine::DefaultScene * scene = (DreamEngine::DefaultScene*)sceneManager->get(data.getInt("scene", false));
	PolygonShapeDef bodyShapeDef;
	/*bodyShapeDef.objectData = data;
	bodyShapeDef.scene = scene;
	bodyShapeDef.sceneManager = builderComponents.sceneManager;*/
	bodyShapeDef.type = "polygonshape";
	bodyShapeDef.cameraManager = cameraManager;
	if (data.hasKey("id")) bodyShapeDef.id = data.getInt("id");
	b2Vec2 bodyPosition = { data.getFloat("bodyPositionX"), data.getFloat("bodyPositionY") };

	bodyShapeDef.body = DreamEngine::WorldComponentsBuilder::instantiateBody(DreamEngine::WorldComponentsBuilder::createBodyDef(b2BodyType(data.getInt("bodyType")), bodyPosition), scene->world);

	//bodyShapeDef.body->SetTransform(bodyShapeDef.body->GetPosition(), .1f);

	//Parse vertices
	b2Vec2 vertices[DreamEngine::Engine::MAX_VERTICES];
	int verticesCount = data.getInt("vertices");
	for (int i = 0; i < verticesCount; i++) {
		vertices[i].x = data.getFloat("verticeX" + std::to_string(i));
		vertices[i].y = data.getFloat("verticeY" + std::to_string(i));
	}

	float density = data.getFloat("density");
	float friction = data.getFloat("friction");
	float restitution = data.getFloat("restitution");

	b2Fixture * fixture = DreamEngine::WorldComponentsBuilder::instantiateFixture(DreamEngine::WorldComponentsBuilder::createFixtureDef(&DreamEngine::WorldComponentsBuilder::createPolygonShape(vertices, verticesCount), density, friction, restitution), bodyShapeDef.body);
	bodyShapeDef.polygonDrawable = (PolygonDrawable*)scene->drawables->get(data.getInt("drawable"));
	PolygonShape * shape = new PolygonShape(bodyShapeDef);
	shape->instantiate(data);
	if (data.hasKey("id")) scene->shapes->add(shape, true);
	else scene->shapes->add(shape, false);
}

DreamEngine::ObjectData PolygonShapeBuilder::getExampleObject()
{
	DreamEngine::ObjectData data;
	data.setString("type", "polygonshape");
	data.setInt("id", 0);
	data.setInt("scene", 0);
	data.setInt("bodytype", 0);
	data.setInt("drawable", 1);
	data.setb2Vec2("bodyPosition", b2Vec2{ 0.f,0.f });
	b2Vec2 vertices[4];
	vertices[0] = { 0,0 };
	vertices[1] = { 0.5f,0 };
	vertices[2] = { 0.5f,0.5f };
	vertices[3] = { 0,.5f };
	data.setb2Vec2Array("vertices", 4, vertices);
	data.setFloat("density", 1.f);
	data.setFloat("friction", 1.f);
	data.setFloat("restitution", 1.f);
	return data;
}
