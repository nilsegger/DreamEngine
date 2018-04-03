#include "DefaultScene.h"

DreamEngine::DefaultScene::DefaultScene(DefaultSceneDef def)
	:collisionListener(def.collisionListener), actors(def.actors), shapes(def.shapes), drawables(def.drawables), world(def.world), Scene(def)
{
	if (collisionListener == nullptr) collisionListener = new CollisionListener;
	if (actors == nullptr) actors = new WorldObjectManager;
	if (shapes == nullptr) shapes = new WorldObjectManager;
	if (drawables == nullptr) drawables = new DrawableManager;

	if (world == nullptr) {
		world = new b2World(def.gravity);
	}
}

void DreamEngine::DefaultScene::update(float delta)
{
	actors->update(delta);
	shapes->update(delta);
}

void DreamEngine::DefaultScene::draw(float delta)
{
	actors->draw(delta);
	shapes->draw(delta);

	/*
	
	type	default-sprite
	scene	1
	id	63
	positionX	100000
	positionY	100000
	sizeX	300000
	sizeY	300000
	spritesheet-positionX	0
	spritesheet-positionY	0
	spritesheet-sizeX	614
	spritesheet-sizeY	640
	spritesheet	rubicscube.png
	shader	shader
	-	-
	*/
	Sprite * sprite = (Sprite*)drawables->get(63);
	if(sprite!=nullptr)	sprite->draw();
	
	
}

void DreamEngine::DefaultScene::destroy()
{
	actors->destroyObjects();
	shapes->destroyObjects();
	drawables->destroyObjects();

	delete world;
	delete collisionListener;
}

void DreamEngine::DefaultScene::load(float * progress)
{
	assert(drawables != nullptr);
	drawables->load(new float);
	isReady = true;
}

void DreamEngine::DefaultScene::start()
{
}

void DreamEngine::DefaultScene::end()
{
}

void DreamEngine::DefaultScene::save(Core::DataManager * dataManager)
{
}
