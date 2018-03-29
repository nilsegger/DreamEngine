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

	Sprite * sprite = (Sprite*)drawables->get(63);
	sprite->draw();
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
