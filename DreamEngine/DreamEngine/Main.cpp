#include "DreamEngine.h"


int main() {

	DreamEngine::WindowDef windowDef;
	windowDef.size = {1280, 720};
	windowDef.style = sf::Style::Close;
	windowDef.title = "DreamEngine";

	DreamEngine::Window * window = new DreamEngine::Window(windowDef);

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

	sceneManager->start();
	
	while (window->isOpen()) {

		sceneManager->baseUpdate();

	}


	return 0;
}