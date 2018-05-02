#include "GameTest.h"



GameTest::GameTest()
{
}


GameTest::~GameTest()
{
	freeMemory();
}

void GameTest::freeMemory()
{
	if (window != nullptr) delete window;
	if (cameraManager != nullptr) delete cameraManager;
	if (builder != nullptr) delete builder;
	if (dataManager != nullptr) delete dataManager;
	if (sceneManager != nullptr) delete sceneManager;
	if (spriteBuilder != nullptr) delete spriteBuilder;
	if (defaultScene != nullptr) delete defaultScene;

	window = nullptr;
	cameraManager = nullptr;
	builder = nullptr;
	dataManager = nullptr;
	sceneManager = nullptr;
	spriteBuilder = nullptr;
	defaultScene = nullptr;
}

void GameTest::init()
{
	DreamEngine::WindowDef windowDef;
	windowDef.fontSize = { 1280, 720 };
	windowDef.style = sf::Style::Close;
	windowDef.title = "DreamEngine";

	window = new DreamEngine::Window(windowDef);

	window->getWindow()->setFramerateLimit(0);
	window->getWindow()->setVerticalSyncEnabled(false);

	cameraManager = new DreamEngine::CameraManager;
	window->setCameraManager(cameraManager);

	DreamEngine::CameraDef cameraDef;
	cameraDef.window = window->getWindow();
	cameraDef.windowSize = { 1280,720 };
	cameraDef.id = 0;

	camera = new DreamEngine::Camera(cameraDef);
	cameraManager->add(camera, true);

	DreamEngine::Builder * builder = new DreamEngine::Builder;

	DreamEngine::DataManagerDef dataManagerDef;
	dataManagerDef.savePath = "test.txt";
	dataManagerDef.loadPath = "shadow-test.lvl.txt";

	dataManager = new DreamEngine::DataManager(dataManagerDef);

	DreamEngine::SceneManagerDef sceneManagerDef;
	sceneManagerDef.builder = builder;
	sceneManagerDef.dataManager = dataManager;
	sceneManagerDef.window = window;

	sceneManager = new DreamEngine::SceneManager(sceneManagerDef);


	PolygonDrawableBuilderDef polygonDrawableBuilderDef;
	polygonDrawableBuilderDef.cameraManager = cameraManager;
	polygonDrawableBuilderDef.sceneManager = sceneManager;
	polygonDrawableBuilderDef.window = window;

	polygonDrawableBuilder = new PolygonDrawableBuilder(polygonDrawableBuilderDef);
	builder->addBuilder(polygonDrawableBuilder);

	PolygonShapeBuilderDef polygonShapeBuilderDef;
	polygonShapeBuilderDef.cameraManager = cameraManager;
	polygonShapeBuilderDef.sceneManager = sceneManager;
	polygonShapeBuilderDef.window = window;

	polygonShapeBuilder = new PolygonShapeBuilder(polygonShapeBuilderDef);
	builder->addBuilder(polygonShapeBuilder);

	DreamEngine::SpriteBuilderDef spriteBuilderDef;
	spriteBuilderDef.cameraManager = cameraManager;
	spriteBuilderDef.sceneManager = sceneManager;
	spriteBuilderDef.window = window;

	//spriteBuilder = new DreamEngine::SpriteBuilder(spriteBuilderDef);
	//builder->addBuilder(spriteBuilder);

	DreamEngine::DefaultSceneDef defaultSceneDef;
	defaultSceneDef.id = 1;
	defaultSceneDef.gravity = { 0.f, 1.f };

	defaultScene = new DreamEngine::DefaultScene(defaultSceneDef);

	sceneManager->add(defaultScene, true);

	sceneManager->start();

	sceneManager->startScene(defaultScene);
}

void GameTest::end()
{
	sceneManager->destroy();
	freeMemory();
}

bool GameTest::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		return false;
	}

	sceneManager->baseUpdate();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
		end();
		init();
	}
	return window->isOpen();
}
