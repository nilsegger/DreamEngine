#include "DreamEngine.h"

#include "PolygonDrawableBuilder.h"
#include "PolygonShapeBuilder.h"

int main() {

	//assert(sf::Shader::isAvailable());

	DreamEngine::WindowDef windowDef;
	windowDef.size = {1280, 720};
	windowDef.style = sf::Style::Close;
	windowDef.title = "DreamEngine";

	DreamEngine::Window * window = new DreamEngine::Window(windowDef);

	window->getWindow()->setFramerateLimit(0);
	window->getWindow()->setVerticalSyncEnabled(false);
	
	DreamEngine::CameraManager * cameraManager = new DreamEngine::CameraManager;
	window->setCameraManager(cameraManager);


	DreamEngine::CameraDef cameraDef;
	cameraDef.window = window->getWindow();
	cameraDef.windowSize = { 1280,720 };
	cameraDef.id = 0;

	DreamEngine::Camera * camera = new DreamEngine::Camera(cameraDef);
	cameraManager->add(camera, true);

	DreamEngine::Builder * builder = new DreamEngine::Builder;

	DreamEngine::DataManagerDef dataManagerDef;
	dataManagerDef.savePath = "test.txt";
	dataManagerDef.loadPath = "test.txt";

	DreamEngine::DataManager * dataManager = new DreamEngine::DataManager(dataManagerDef);

	DreamEngine::SceneManagerDef sceneManagerDef;
	sceneManagerDef.builder = builder;
	sceneManagerDef.dataManager = dataManager;
	sceneManagerDef.window = window;

	DreamEngine::SceneManager * sceneManager = new DreamEngine::SceneManager(sceneManagerDef);


	PolygonDrawableBuilderDef polygonDrawableBuilderDef;
	polygonDrawableBuilderDef.cameraManager = cameraManager;
	polygonDrawableBuilderDef.sceneManager = sceneManager;
	polygonDrawableBuilderDef.window = window;

	PolygonDrawableBuilder * polygonDrawableBuilder = new PolygonDrawableBuilder(polygonDrawableBuilderDef);
	builder->addBuilder(polygonDrawableBuilder);

	PolygonShapeBuilderDef polygonShapeBuilderDef;
	polygonShapeBuilderDef.cameraManager = cameraManager;
	polygonShapeBuilderDef.sceneManager = sceneManager;
	polygonShapeBuilderDef.window = window;

	PolygonShapeBuilder * polygonShapeBuilder = new PolygonShapeBuilder(polygonShapeBuilderDef);
	builder->addBuilder(polygonShapeBuilder);

	DreamEngine::DefaultSceneDef defaultSceneDef;
	defaultSceneDef.id = 1;
	defaultSceneDef.gravity = {0.f, 1.f};
	
	DreamEngine::DefaultScene * defaultScene = new DreamEngine::DefaultScene(defaultSceneDef);

	sceneManager->add(defaultScene, true);

	sceneManager->startScene(defaultScene);

	sceneManager->start();
	

	sf::RectangleShape rect;
	rect.setPosition(0, 0);
	rect.setSize({ 100,100 });

	while (window->isOpen()) {

		sceneManager->baseUpdate();

	}

	std::cout << "Window closed" << std::endl;

	delete window;
	delete cameraManager;
	delete builder;
	delete dataManager;
	delete sceneManager;
	delete polygonDrawableBuilder;
	delete defaultScene;


	return 0;
}