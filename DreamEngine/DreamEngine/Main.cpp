#include "DreamEngine.h"

#include "PolygonDrawableBuilder.h"
#include "PolygonShapeBuilder.h"

#include "Lightning.h"



int main() {

	std::cout << DreamEngine::Engine::angleToForward(DreamEngine::Engine::degToRadian(45.f)).x << "#" << DreamEngine::Engine::angleToForward(DreamEngine::Engine::degToRadian(45.f)).y << std::endl;

	assert(sf::Shader::isAvailable());
	

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
	dataManagerDef.loadPath = "shadow-test.lvl.txt";

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

	DreamEngine::SpriteBuilderDef spriteBuilderDef;
	spriteBuilderDef.cameraManager = cameraManager;
	spriteBuilderDef.sceneManager = sceneManager;
	spriteBuilderDef.window = window;

	DreamEngine::SpriteBuilder * spriteBuilder = new DreamEngine::SpriteBuilder(spriteBuilderDef);
	builder->addBuilder(spriteBuilder);

	DreamEngine::DefaultSceneDef defaultSceneDef;
	defaultSceneDef.id = 1;
	defaultSceneDef.gravity = {0.f, 1.f};
	
	DreamEngine::DefaultScene * defaultScene = new DreamEngine::DefaultScene(defaultSceneDef);

	sceneManager->add(defaultScene, true);

	sceneManager->start();
	
	sceneManager->startScene(defaultScene);

	sf::RectangleShape rect;
	rect.setPosition(0, 0);
	rect.setSize({ 100,100 });
	

	DreamEngine::DirectionalLightningDef lightningDef;

	lightningDef.position = {0,0};
	lightningDef.forward = { 1.f,1.f };
	lightningDef.range = 10.f;
	lightningDef.window = window->getWindow();
	lightningDef.windowSize = {1280,720};
	lightningDef.world = defaultScene->world;
	
	DreamEngine::DirectionalLightning dirLightning(lightningDef);

	bool isLess = false;

	while (window->isOpen()) {
		sceneManager->baseUpdate();

		if (window->fpsCounter.getFrames() < 60 && isLess == false) {
			std::cout << "Less than 60 frames per second" << std::endl;
			isLess = true;
		}
		else if (window->fpsCounter.getFrames() >= 60 && isLess == true) {
			std::cout << "More than 60 frames per second" << std::endl;
			isLess = false;
		}

	/*	window->getWindow()->clear(sf::Color::Black);

		dirLightning.get();
		
		window->getWindow()->display();*/
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